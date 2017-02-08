//
// Created by brout_m on 07/02/17.
//


#include <algorithm>
#include <stdexcept>
#include <Gates.hh>
#include "ComponentOutput.hh"

nts::ComponentOutput::ComponentOutput(std::string const &name) :
        AComponent(name,
                   nts::COMPONENTOUTPUT,
                   2,
                   {1},
                   {1},
                   {})
{
}

nts::Tristate nts::ComponentOutput::Compute(size_t pin_num_this) {
    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");
    if (Pins[1] == UNDEFINED)
        Pins[1] = getPinLinkedInput(1);
    return (Pins[1]);
}