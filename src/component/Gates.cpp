//
// Created by brout_m on 06/02/17.
//

#include "Gates.hh"

nts::Tristate nts::Gates::nand(nts::Tristate in1, nts::Tristate in2) const
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((!(in1 == TRUE && in2 == TRUE)) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::nor(nts::Tristate in1, nts::Tristate in2) const
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((!(in1 == TRUE || in2 == TRUE)) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::_and(nts::Tristate in1, nts::Tristate in2) const
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((in1 == TRUE && in2 == TRUE) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::_or(nts::Tristate in1, nts::Tristate in2) const
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((in1 == TRUE || in2 == TRUE) ? TRUE : FALSE);
}

nts::Tristate nts::Gates::add(nts::Tristate in1, nts::Tristate in2, nts::Tristate& ret) const
{
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    if (in1 == in2 && in1 == TRUE)
        ret = TRUE;
    return ((in1 == in2) ? FALSE : TRUE);
}

nts::Tristate nts::Gates::flipflop(nts::Tristate clock,
                                   nts::Tristate reset,
                                   nts::Tristate data,
                                   nts::Tristate set,
                                   nts::Tristate& q,
                                   nts::Tristate& nq,
                                   bool which) const
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
        nq = -q;
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

nts::Tristate nts::Gates::_xor(nts::Tristate in1, nts::Tristate in2) const {
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return (in1 != in2 ? TRUE : FALSE);
}
