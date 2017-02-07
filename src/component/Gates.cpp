//
// Created by brout_m on 06/02/17.
//

#include "Gates.hh"

nts::Tristate nts::Gates::nand(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((!(in1 == TRUE && in2 == TRUE)) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::nor(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((!(in1 == TRUE || in2 == TRUE)) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::_and(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((in1 == TRUE && in2 == TRUE) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::_or(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((in1 == TRUE || in2 == TRUE) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::add(nts::Tristate in1, nts::Tristate in2, nts::Tristate& co)
{
    nts::Tristate add;
    nts::Tristate ret;

    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);

    ret = FALSE;
    if (in1 != in2) {
        add = TRUE;
    } else  {
        if (in1 == TRUE)
            ret = TRUE;
        add = FALSE;
    }
    if (co != UNDEFINED) {
        if (add == TRUE && co == TRUE)
            ret = TRUE;
        add = (add != co ? TRUE : FALSE);
    }
    co = ret;
    return (add);
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
