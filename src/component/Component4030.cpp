//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include "Gates.hh"
#include "Component4030.hh"

nts::Component4030::Component4030(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4030,
                   14,
                   {1, 2, 5, 6, 8, 9, 12, 13},
                   {3, 4, 10, 11})
{
}

nts::Tristate nts::Component4030::Compute(size_t pin_num_this)
{
    nts::Tristate state;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        switch (pin_num_this) {
            case 3 : state = Pins[3] = Gates::_xor(Pins[1], Pins[2]); break;
            case 4 : state = Pins[4] = Gates::_xor(Pins[5], Pins[6]); break;
            case 10 : state = Pins[10] = Gates::_xor(Pins[8], Pins[9]); break;
            case 11 : state = Pins[11] = Gates::_xor(Pins[12], Pins[13]); break;
            default: state = UNDEFINED;
        }
    }
    return (state);
}