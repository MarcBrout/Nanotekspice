//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "Component4071.hh"
#include "Gates.hh"

nts::Component4071::Component4071(std::string const &name) :
    AComponent(name,
               nts::COMPONENT4071,
               14,
               {1, 2, 5, 6, 8, 9, 12, 13},
               {3, 4, 10, 11},
               {{3, {1, 2}},
                {4, {5, 6}},
                {10, {8, 9}},
                {11, {12, 13}},
               })
{
}

nts::Tristate nts::Component4071::Compute(size_t pin_num_this) {
    nts::Tristate state;
    std::vector<nts::Output>::iterator  it;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        ComputeRequiredPins(pin_num_this);
        it = std::find(Required.begin(), Required.end(), pin_num_this);
        if (it != Required.end())
            state = Pins[pin_num_this] = Gates::_or(Pins[it->required[0]], Pins[it->required[1]]);
        else
            state = UNDEFINED;
    }
    return (state);
}
