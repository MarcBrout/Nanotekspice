//
// Created by brout_m on 06/02/17.
//


#include <stdexcept>
#include "Component4008.hh"
#include "Gates.hh"

nts::Component4008::Component4008(std::string const &name) :
    AComponent(name,
               nts::COMPONENT4008,
               16,
               {1, 2, 3, 4, 5, 6, 7, 9, 15},
               {10, 11, 12, 13, 14})
{
}

nts::Tristate nts::Component4008::Compute(size_t pin_num_this) {
    nts::Tristate state;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        switch (pin_num_this) {
            case 10 : Pins[10] = Gates::add(Pins[6], Pins[7], Pins[14]);
                state = Pins[10] = Gates::add(Pins[10], Pins[9], Pins[14]); break;
            case 11 : Pins[11] = Gates::add(Pins[4], Pins[5], Pins[14]);
                state = Pins[11] = Gates::add(Pins[11], Pins[10], Pins[14]); break;
            case 12 : Pins[12] = Gates::add(Pins[2], Pins[3], Pins[14]);
                state = Pins[12] = Gates::add(Pins[12], Pins[11], Pins[14]); break;
            case 13 : Pins[13] = Gates::add(Pins[1], Pins[15], Pins[14]);
                state = Pins[13] = Gates::add(Pins[13], Pins[12], Pins[14]); break;
            case 14 : state = Pins[14]; break;
            default: state = UNDEFINED;
        }
    }
    return (state);
}
