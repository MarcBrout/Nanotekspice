//
// Created by brout_m on 02/02/17.
//

#include <algorithm>
#include <stdexcept>
#include <map>
#include "Component4512.hh"
#include "Gates.hh"

nts::Component4512::Component4512(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4512,
                   16,
                   {INHIB, OE, X0, X1, X2, X3, X4, X5, X6, X7, A, B, C},
                   {Z},
                   {{Z, {INHIB, OE, X0, X1, X2, X3, X4, X5, X6, X7, A, B, C}}
                   })
{
}

static std::map<size_t , nts::Component4512::PINS> doors = {
        {0, nts::Component4512::X0},
        {1, nts::Component4512::X1},
        {2, nts::Component4512::X2},
        {3, nts::Component4512::X3},
        {4, nts::Component4512::X4},
        {5, nts::Component4512::X5},
        {6, nts::Component4512::X6},
        {7, nts::Component4512::X7},
};

nts::Tristate nts::Component4512::Compute(size_t pin_num_this)
{
    nts::Tristate                       state;
    std::vector<nts::Output>::iterator  it;
    size_t                              ind;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
         state = getPinLinkedInput(pin_num_this);
    } else {
        ComputeRequiredPins(pin_num_this);
        it = std::find(Required.begin(), Required.end(), pin_num_this);
        if (it != Required.end()) {
            if (Pins[nts::Component4512::OE] == TRUE) {
                state = Pins[pin_num_this] = UNDEFINED;
            } else if (Pins[nts::Component4512::INHIB] == TRUE) {
                state = Pins[pin_num_this] = FALSE;
            } else {
                ind = Pins[nts::Component4512::A] == TRUE ? 1 : 0;
                ind += Pins[nts::Component4512::B] == TRUE ? 2 : 0;
                ind += Pins[nts::Component4512::C] == TRUE ? 4 : 0;
                state = Pins[pin_num_this] = Pins[doors[ind]];
            }
        }
        else
            state = UNDEFINED;
    }
    return (state);
}
