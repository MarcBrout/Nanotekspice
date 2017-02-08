//
// Created by brout_m on 08/02/17.
//

#include <algorithm>
#include <stdexcept>
#include <Gates.hh>
#include "ComponentFalse.hh"

nts::ComponentFalse::ComponentFalse(std::string const &name) :
        AComponent(name,
                   nts::COMPONENTFALSE,
                   2,
                   {},
                   {1},
                   {})
{
}

nts::Tristate nts::ComponentFalse::Compute(size_t pin_num_this) {
    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    return (FALSE);
}