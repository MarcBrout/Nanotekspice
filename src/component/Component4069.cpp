//
// Created by brout_m on 06/02/17.
//

#include <algorithm>
#include <stdexcept>
#include "Component4069.hh"
#include "Gates.hh"

nts::Component4069::Component4069(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4069,
                   14,
                   {1, 3, 5, 9, 11, 13},
                   {2, 4, 6, 8, 10, 12},
                   {{2, {1}},
                    {4, {3}},
                    {6, {5}},
                    {8, {9}},
                    {10, {11}},
                    {12, {13}}
                   })
{
}

nts::Tristate nts::Component4069::Compute(size_t pin_num_this)
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
            state = Pins[pin_num_this] = Gates::inverter(Pins[it->required[0]]);
        else
            state = UNDEFINED;
    }
    return (state);
}
