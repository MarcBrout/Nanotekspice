//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "Gates.hh"
#include "Component4017.hh"

nts::Component4017::Component4017(std::string const &name) :
        AComponent(name,
                   nts::COMPONENT4017,
                   16,
                   {CP1, CP0, MR},
                   {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q59},
                   {{Q0, {CP1, CP0, MR}},
                    {Q1, {CP1, CP0, MR}},
                    {Q2, {CP1, CP0, MR}},
                    {Q3, {CP1, CP0, MR}},
                    {Q4, {CP1, CP0, MR}},
                    {Q5, {CP1, CP0, MR}},
                    {Q6, {CP1, CP0, MR}},
                    {Q7, {CP1, CP0, MR}},
                    {Q8, {CP1, CP0, MR}},
                    {Q9, {CP1, CP0, MR}},
                    {Q59, {CP1, CP0, MR}},
                   }),
        cp0State(false),
        computedOnce(false)
{
    resetMe();
}

nts::Tristate nts::Component4017::Compute(size_t pin_num_this)
{
    std::vector<size_t>::const_iterator it;
    nts::Tristate clockState;
    nts::Tristate state;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        clockState = cp0State ? Pins[CP0] : Pins[CP1];
        state = getPinLinkedInput(pin_num_this);
        if (pin_num_this == CP0 && cp0State && !computedOnce) {
            if (clockState == FALSE && state == TRUE) {
                it = std::find_if(InPins.cbegin(), InPins.cend(), [&Pins](size_t pin){ return (Pins[pin] == TRUE); });
                if (it != InPins.cend()) {
                    if (*it != Q9) {
                        Pins[*it] = FALSE;
                        Pins[*it + 1] = TRUE;
                        if (*it == Q4 || *it == Q6 || *it == Q7 || *it == Q8)
                            Pins[Q59] = FALSE;
                    } else {
                        resetMe();
                    }
                    computedOnce = true;
                }
            }
        }
        if (pin_num_this == CP1 && !cp0State && !computedOnce) {
            Pins[CP1] = Gates::inverter(Pins[CP1]);
            if (clockState == TRUE && state == FALSE) {
                it = std::find_if(InPins.cbegin(), InPins.cend(), [&Pins](size_t pin){ return (Pins[pin] == TRUE); });
                if (it != InPins.cend()) {
                    if (*it != Q9) {
                        Pins[*it] = FALSE;
                        Pins[*it + 1] = TRUE;
                        if (*it == Q4 || *it == Q6 || *it == Q7 || *it == Q8)
                            Pins[Q59] = FALSE;
                    } else {
                        resetMe();
                    }
                    computedOnce = true;
                }
            }
        }
        if (pin_num_this == MR)
        {
            resetMe();
            computedOnce = true;
        }
    } else {
        ComputeRequiredPins(pin_num_this);
        return (Pins[pin_num_this]);
    }
    return (state);
}

void nts::Component4017::resetMe() {
    std::for_each(InPins.cbegin(), InPins.cend(), [&Pins](size_t pin){ Pins[pin] = FALSE; });
    Pins[Q0] = TRUE;
    Pins[Q59] = TRUE;
    cp0State = -cp0State;
}

void nts::Component4017::resetComputedPins(void) {
    AComponent::resetComputedPins();
    computedOnce = false;
}
