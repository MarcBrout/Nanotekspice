//
// Created by brout_m on 10/02/17.
//


#include <algorithm>
#include <stdexcept>
#include "Component2716.hh"
#include "Gates.hh"

nts::Component2716::Component2716(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT2716,
                   24,
                   {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10},
                   {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7},
                   {{Q0, {1, 2}}
                   })
{
}

nts::Tristate nts::Component2716::Compute(size_t pin_num_this)
{
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
            state = Pins[pin_num_this] = Gates::nor(Pins[it->required[0]], Pins[it->required[1]]);
        else
            state = UNDEFINED;
    }
    return (state);
}

