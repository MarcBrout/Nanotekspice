//
// Created by brout_m on 08/02/17.
//

#include <algorithm>
#include <stdexcept>
#include <Gates.hh>
#include "ComponentClock.hh"

nts::ComponentClock::ComponentClock(std::string const &name) :
        AComponent(name,
                   nts::COMPONENTCLOCK,
                   2,
                   {},
                   {1},
                   {}),
        Reset(false)
{
    Pins[1] = FALSE;
}

nts::Tristate nts::ComponentClock::Compute(size_t pin_num_this) {
    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (Reset) {
        Pins[1] = Gates::inverter(Pins[1]);
        Reset = false;
    }
    return (Pins[1]);
}

void nts::ComponentClock::resetComputedPins(void) {
    Reset = true;
}
