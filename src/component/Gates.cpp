//
// Created by brout_m on 06/02/17.
//

#include "Gates.hh"

nts::Tristate nts::Gates::nand(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == FALSE || in2 == FALSE)
        return (TRUE);
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (FALSE);
}

nts::Tristate nts::Gates::nor(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == TRUE || in2 == TRUE)
        return (FALSE);
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (TRUE);
}

nts::Tristate nts::Gates::_and(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == FALSE || in2 == FALSE)
        return (FALSE);
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (TRUE);
}

nts::Tristate nts::Gates::_or(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == TRUE || in2 == TRUE)
        return (TRUE);
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (FALSE);
}

nts::Tristate nts::Gates::add(nts::Tristate in1, nts::Tristate in2, nts::Tristate& co)
{
    nts::Tristate add;

    add = _xor(in1, in2);
    co = _or(_and(add, co), _and(in1, in2));
    return (_xor(add, co));
}

nts::Tristate nts::Gates::flipflop(nts::Tristate clock,
                                   nts::Tristate reset,
                                   nts::Tristate data,
                                   nts::Tristate set,
                                   nts::Tristate& q,
                                   nts::Tristate& nq,
                                   bool which)
{
    if (clock == UNDEFINED || reset == UNDEFINED || set == UNDEFINED ||
        (clock == TRUE && data == UNDEFINED)) {
        q = UNDEFINED;
        nq = UNDEFINED;
        return (UNDEFINED);
    }

    if (set == FALSE && reset == FALSE)
    {
        if (clock == TRUE)
            q = data;
        nq = (q == TRUE ? FALSE : TRUE);
        return (which ? q : nq);
    }

    if (set == TRUE && reset == TRUE)
    {
        q = TRUE;
        nq = TRUE;
        return (which ? q : nq);
    }

    if (reset == TRUE)
    {
        q = FALSE;
        nq = TRUE;
        return (which ? q : nq);
    }

    q = TRUE;
    nq = FALSE;
    return (which ? q : nq);
}

nts::Tristate nts::Gates::_xor(nts::Tristate in1, nts::Tristate in2) {
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (in1 != in2 ? TRUE : FALSE);
}

nts::Tristate nts::Gates::inverter(nts::Tristate in1) {
    if (in1 == UNDEFINED)
        return (in1);
    return (in1 == TRUE ? FALSE : TRUE);
}

nts::Tristate nts::Gates::_and(nts::Tristate in1, nts::Tristate in2, nts::Tristate in3, nts::Tristate in4) {
    return (_and(_and(in1, in2), _and(in3, in4)));
}
