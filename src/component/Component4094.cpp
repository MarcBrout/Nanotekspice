//
// Created by brout_m on 10/02/17.
//

#include <algorithm>
#include <stdexcept>
#include "Component4094.hh"
#include "Gates.hh"

nts::Component4094::Component4094(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4094,
                   16,
               {STROBE, DATA, CP0, OUT},
                   {Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, QS, NQS},
                   {{Q1, {STROBE, DATA, CP0, OUT}},
                    {Q2, {STROBE, DATA, CP0, OUT}},
                    {Q3, {STROBE, DATA, CP0, OUT}},
                    {Q4, {STROBE, DATA, CP0, OUT}},
                    {Q5, {STROBE, DATA, CP0, OUT}},
                    {Q6, {STROBE, DATA, CP0, OUT}},
                    {Q7, {STROBE, DATA, CP0, OUT}},
                    {Q8, {STROBE, DATA, CP0, OUT}},
                    {QS, {STROBE, DATA, CP0, OUT}},
                    {NQS, {STROBE, DATA, CP0, OUT}},
                   }),
        bit(0),
        computed(false)
{
}

nts::Tristate nts::Component4094::Compute(size_t pin_num_this)
{
    nts::Tristate                       state;
    nts::Tristate                       clockState;
    std::vector<nts::Output>::iterator  it;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        clockState = Pins[CP0];
        state = getPinLinkedInput(pin_num_this);
        if (!computed) {
            if (clockState == FALSE && state == TRUE) {
                Pins[QS] = Pins [Q8] = Pins[Q7];
            } else if (clockState == TRUE && state == FALSE) {
                Pins[NQS] = Pins[Q7];
            }
            computed = true;
            state = Pins[pin_num_this];
        }
    } else {
        clockState = Pins[CP0];
        ComputeRequiredPins(pin_num_this);
        if (Pins[OUT] == FALSE) {
            if (Pins[CP0] == FALSE) {
                switch (pin_num_this) {
                    case QS : state = Pins[QS] = Pins[Q7]; break;
                    case NQS : state = Pins[NQS]; break;
                    default: state = UNDEFINED;
                }
            } else {
                switch (pin_num_this) {
                    case QS : state = Pins[QS]; break;
                    case NQS : state = Pins[NQS] = Pins[Q7]; break;
                    default: state = UNDEFINED;
                }
            }
        } else if (Pins[STROBE] == TRUE && clockState == FALSE && Pins[CP0] == TRUE) {
            bit = bit << 1;
            bit += (Pins[DATA] == TRUE) ? 1 : 0;
            Pins[Q1] = (bit & 0x01) ? TRUE : FALSE;
            Pins[Q2] = (bit & 0x02) ? TRUE : FALSE;
            Pins[Q3] = (bit & 0x04) ? TRUE : FALSE;
            Pins[Q4] = (bit & 0x08) ? TRUE : FALSE;
            Pins[Q5] = (bit & 0x10) ? TRUE : FALSE;
            Pins[Q6] = (bit & 0x20) ? TRUE : FALSE;
            Pins[Q7] = (bit & 0x40) ? TRUE : FALSE;
            Pins[Q8] = (bit & 0x80) ? TRUE : FALSE;
            Pins[QS] = Pins[Q7];
            state = Pins[pin_num_this];
        } else {
            if (Pins[STROBE] == TRUE && clockState == TRUE && Pins[CP0] == FALSE)
                Pins[NQS] = Pins[Q7];
            state = Pins[pin_num_this];
        }

    }
    return (state);
}

void nts::Component4094::resetComputedPins(void) {
    AComponent::resetComputedPins();
    computed = false;
}
