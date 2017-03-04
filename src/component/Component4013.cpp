//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "Component4013.hh"
#include "Gates.hh"

nts::Component4013::Component4013(std::string const &name) :
        AComponent(name,
                   nts::COMPONENT4013,
                   14,
                   {CP1, CP2, RESET1, RESET2, DATA1, DATA2, SET1, SET2},
                   {KQ1, NQ1, KQ2, NQ2},
                   {{KQ1, {CP1, RESET1, DATA1, SET1}},
                    {NQ1, {CP1, RESET1, DATA1, SET1}},
                    {KQ2, {CP2, RESET2, DATA2, SET2}},
                    {NQ2, {CP2, RESET2, DATA2, SET2}}
                   })
{
}

nts::Tristate nts::Component4013::Compute(size_t pin_num_this) {
    nts::Tristate                       state;
    nts::Tristate                       clockState1;
    nts::Tristate                       clockState2;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        clockState1 = Pins[CP1];
        clockState2 = Pins[CP2];
        ComputeRequiredPins(pin_num_this);
        if (pin_num_this == KQ1 || pin_num_this == NQ1) {
            if (Pins[CP1] == TRUE && (clockState1 == FALSE || clockState1 == UNDEFINED)) {
                if (pin_num_this == KQ1)
                    state = Pins[1] = Gates::flipflop(Pins[3], Pins[4], Pins[5], Pins[6], Pins[1], Pins[2], true);
                else
                    state = Pins[2] = Gates::flipflop(Pins[3], Pins[4], Pins[5], Pins[6], Pins[1], Pins[2], false);
            } else {
                state = Pins[pin_num_this];
            }
        } else {
            if (Pins[CP2] == TRUE && (clockState2 == FALSE || clockState2 == UNDEFINED)) {
                if (pin_num_this == KQ2)
                    state = Pins[12] = Gates::flipflop(Pins[11], Pins[10], Pins[9], Pins[8], Pins[13], Pins[12], false);
                else
                    state = Pins[13] = Gates::flipflop(Pins[11], Pins[10], Pins[9], Pins[8], Pins[13], Pins[12], true);
            } else {
                state = Pins[pin_num_this];
            }
        }
    }
    return (state);
}

