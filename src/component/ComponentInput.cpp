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
                   2,
                   {},
                   {},
                   {})
{
}

nts::Tristate nts::ComponentInput::Compute(size_t pin_num_this) {
    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    return (Pins[1]);
}