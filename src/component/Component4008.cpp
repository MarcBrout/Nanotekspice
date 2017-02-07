//
// Created by brout_m on 06/02/17.
//


#include <stdexcept>
#include <algorithm>
#include "Component4008.hh"
#include "Gates.hh"

nts::Component4008::Component4008(std::string const &name) :
    AComponent(name,
               nts::COMPONENT4008,
               16,
               {1, 2, 3, 4, 5, 6, 7, 9, 15},
               {10, 11, 12, 13},
               {{10, {6, 7, 9}},
                {11, {4, 5, 10}},
                {12, {2, 3, 11}},
                {13, {1, 15, 12}},
                {14, {13}}
               })
{
}

nts::Tristate nts::Component4008::Compute(size_t pin_num_this) {
    nts::Tristate                       state;
    std::vector<nts::Output>::iterator  it;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        ComputeRequiredPins(pin_num_this);
        it = std::find(Required.begin(), Required.end(), pin_num_this);
        if (it != Required.end())
        {
            if (pin_num_this != 14) {
                state = Pins[14];
            } else {
                state = Pins[pin_num_this] = Gates::add(Pins[it->required[0]], Pins[it->required[1]], Pins[14]);
            }
        } else {
            state = UNDEFINED;
        }
    }
    return (state);
}
