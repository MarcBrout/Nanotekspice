//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "Component4040.hh"
#include "Gates.hh"



nts::Component4040::Component4040(std::string const &name) :
        AComponent(name,
                   nts::COMPONENT4040,
                   16,
                   {RESET, CP0},
                   {Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12},
                   {{Q1, {CP0, RESET}},
                    {Q2, {CP0, RESET}},
                    {Q3, {CP0, RESET}},
                    {Q4, {CP0, RESET}},
                    {Q5, {CP0, RESET}},
                    {Q6, {CP0, RESET}},
                    {Q7, {CP0, RESET}},
                    {Q8, {CP0, RESET}},
                    {Q9, {CP0, RESET}},
                    {Q10, {CP0, RESET}},
                    {Q11, {CP0, RESET}},
                    {Q12, {CP0, RESET}}
                   }),
        computed(false)
{
    resetMe();
}

nts::Tristate nts::Component4040::Compute(size_t pin_num_this) {
    static uint16_t bit = 0;
    nts::Tristate state;
    nts::Tristate cpoState;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        if (!computed) {
            cpoState = Pins[CP0];
            state = getPinLinkedInput(pin_num_this);
            if (Pins[RESET] == TRUE) {
                resetMe();
                bit = 0;
            } else if (pin_num_this == CP0 && cpoState == TRUE && state == FALSE) {
                if (bit == 0xFFF) {
                    resetMe();
                    bit = 0;
                }
                ++bit;
                Pins[Q1] = (bit & 0x001) ? TRUE : FALSE;
                Pins[Q2] = (bit & 0x002) ? TRUE : FALSE;
                Pins[Q3] = (bit & 0x004) ? TRUE : FALSE;
                Pins[Q4] = (bit & 0x008) ? TRUE : FALSE;
                Pins[Q5] = (bit & 0x010) ? TRUE : FALSE;
                Pins[Q6] = (bit & 0x020) ? TRUE : FALSE;
                Pins[Q7] = (bit & 0x040) ? TRUE : FALSE;
                Pins[Q8] = (bit & 0x080) ? TRUE : FALSE;
                Pins[Q9] = (bit & 0x100) ? TRUE : FALSE;
                Pins[Q10] = (bit & 0x200) ? TRUE : FALSE;
                Pins[Q11] = (bit & 0x400) ? TRUE : FALSE;
                Pins[Q12] = (bit & 0x800) ? TRUE : FALSE;
            }
            computed = true;
        }
        state = Pins[pin_num_this];
    } else {
        ComputeRequiredPins(pin_num_this);
        return (Pins[pin_num_this]);
    }
    return (state);
}

void nts::Component4040::resetComputedPins(void) {
    AComponent::resetComputedPins();
    computed = false;
}

void nts::Component4040::resetMe() {
    std::for_each(OutPins.cbegin(), OutPins.cend(), [this](size_t pin){ this->Pins[pin] = FALSE; });
}
