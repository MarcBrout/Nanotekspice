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

nts::Tristate nts::Gates::add(nts::Tristate in1, nts::Tristate in2) {
    if (in1 == UNDEFINED || in2 == UNDEFINED)
        return (UNDEFINED);
    return ((in1 == in2) ? FALSE : TRUE);
}
