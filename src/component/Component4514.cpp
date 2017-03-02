//
// Created by brout_m on 06/02/17.
//

#include <algorithm>
#include <stdexcept>
#include "Component4514.hh"
#include "Gates.hh"

nts::Component4514::Component4514(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4514,
                   24,
                   {1, 2, 3, 21, 22, 23},
                   {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15},
                   {{11, {1, 2, 3, 21, 22, 23}},
                    {9, {1, 2, 3, 21, 22, 23}},
                    {10, {1, 2, 3, 21, 22, 23}},
                    {8, {1, 2, 3, 21, 22, 23}},
                    {7, {1, 2, 3, 21, 22, 23}},
                    {6, {1, 2, 3, 21, 22, 23}},
                    {5, {1, 2, 3, 21, 22, 23}},
                    {4, {1, 2, 3, 21, 22, 23}},
                    {18, {1, 2, 3, 21, 22, 23}},
                    {17, {1, 2, 3, 21, 22, 23}},
                    {20, {1, 2, 3, 21, 22, 23}},
                    {19, {1, 2, 3, 21, 22, 23}},
                    {14, {1, 2, 3, 21, 22, 23}},
                    {13, {1, 2, 3, 21, 22, 23}},
                    {16, {1, 2, 3, 21, 22, 23}},
                    {15, {1, 2, 3, 21, 22, 23}}
                   }),
        latches(4, UNDEFINED)
{
}

nts::Tristate nts::Component4514::Compute(size_t pin_num_this)
{
    nts::Tristate state;
    nts::Tristate strobeState;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
        strobeState = Pins[1];
        if (pin_num_this == 1 && strobeState == TRUE && state == TRUE)
        {
            latches[A] = Pins[2] = getPinLinkedInput(2);
            latches[B] = Pins[3] = getPinLinkedInput(3);
            latches[C] = Pins[21] = getPinLinkedInput(21);
            latches[D] = Pins[22] = getPinLinkedInput(22);
        }
    } else {
        ComputeRequiredPins(pin_num_this);
        if (Pins[23] == TRUE)
        {
            state = FALSE;
        }
        else
        {
            if (!isComputed) {
                Pins[S0] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                       Gates::inverter(latches[C]), Gates::inverter(latches[D]));
                Pins[S1] = Gates::_and(latches[A], Gates::inverter(latches[B]), Gates::inverter(latches[C]),
                                       Gates::inverter(latches[D]));
                Pins[S2] = Gates::_and(Gates::inverter(latches[A]), latches[B], Gates::inverter(latches[C]),
                                       Gates::inverter(latches[D]));
                Pins[S3] = Gates::_and(latches[A], latches[B], Gates::inverter(latches[C]),
                                       Gates::inverter(latches[D]));
                Pins[S4] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]), latches[C],
                                       Gates::inverter(latches[D]));
                Pins[S5] = Gates::_and(latches[A], Gates::inverter(latches[B]), latches[C],
                                       Gates::inverter(latches[D]));
                Pins[S6] = Gates::_and(Gates::inverter(latches[A]), latches[B], latches[C],
                                       Gates::inverter(latches[D]));
                Pins[S7] = Gates::_and(latches[A], latches[B], latches[C], Gates::inverter(latches[D]));
                Pins[S8] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                       Gates::inverter(latches[C]), latches[D]);
                Pins[S9] = Gates::_and(latches[A], Gates::inverter(latches[B]), Gates::inverter(latches[C]),
                                       latches[D]);
                Pins[S10] = Gates::_and(Gates::inverter(latches[A]), latches[B], Gates::inverter(latches[C]),
                                        latches[D]);
                Pins[S11] = Gates::_and(latches[A], latches[B], Gates::inverter(latches[C]), latches[D]);
                Pins[S12] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]), latches[C],
                                        latches[D]);
                Pins[S13] = Gates::_and(latches[A], Gates::inverter(latches[B]), latches[C], latches[D]);
                Pins[S14] = Gates::_and(Gates::inverter(latches[A]), latches[B], latches[C], latches[D]);
                Pins[S15] = Gates::_and(latches[A], latches[B], latches[C], latches[D]);
                isComputed = true;
            }
            state = Pins[pin_num_this];
        }
    }
    return (state);
}

void nts::Component4514::resetComputedPins(void) {
    AComponent::resetComputedPins();
    isComputed = false;
}
