//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "../../include/Component4013.hh"
#include "../../include/Gates.hh"

nts::Component4013::Component4013(std::string const &name) :
        AComponent(name,
                   nts::COMPONENT4013,
                   14,
                   {3, 4, 5, 6, 8, 9, 10, 11},
                   {1, 2, 12, 13},
                   {{1, {3, 4, 5, 6}},
                    {2, {3, 4, 5, 6}},
                    {12, {8, 9, 10, 11}},
                    {13, {8, 9, 10, 11}}
                   })
{
}

nts::Tristate nts::Component4013::Compute(size_t pin_num_this) {
    nts::Tristate                       state;
    std::vector<nts::Output>::iterator  it;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        ComputeRequiredPins(pin_num_this);
        switch (pin_num_this) {
            case 1 : state = Pins[1] = Gates::flipflop(Pins[3], Pins[4], Pins[5], Pins[6], Pins[1], Pins[2], true); break;
            case 2 : state = Pins[2] = Gates::flipflop(Pins[3], Pins[4], Pins[5], Pins[6], Pins[1], Pins[2], false); break;
            case 12 : state = Pins[12] = Gates::flipflop(Pins[11], Pins[10], Pins[9], Pins[8], Pins[13], Pins[12], false); break;
            case 13 : state = Pins[13] = Gates::flipflop(Pins[11], Pins[10], Pins[9], Pins[8], Pins[13], Pins[12], true); break;
            default: state = UNDEFINED;
        }
    }
    return (state);
}

