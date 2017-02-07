//
// Created by brout_m on 07/02/17.
//

#include <algorithm>
#include <stdexcept>
#include <Gates.hh>
#include "ComponentInput.hh"

nts::ComponentInput::ComponentInput(std::string const &name) :
        AComponent(name,
                   nts::COMPONENTINPUT,
                   3,
                   {1},
                   {2},
                   {{2, {1}}})
{
}

nts::Tristate nts::ComponentInput::Compute(size_t pin_num_this) {
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
            state = Pins[pin_num_this];
        else
            state = UNDEFINED;
    }
    return (state);
}

