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
        strobeState = Pins[1];
        state = getPinLinkedInput(pin_num_this);
        if (pin_num_this == 1 && strobeState == TRUE && state == FALSE)
        {
            latches[A] = Pins[2] = getPinLinkedInput(2);
            latches[B] = Pins[3] = getPinLinkedInput(3);
            latches[C] = Pins[21] = getPinLinkedInput(21);
            latches[D] = Pins[22] = getPinLinkedInput(22);
        }
    } else {
        ComputeRequiredPins(pin_num_this);
        if ((Pins[23] = getPinLinkedInput(23)) == TRUE)
        {
            state = FALSE;
        }
        else
        {
            switch (pin_num_this) {
                case S0 :
                    state = Pins[S0] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                                   Gates::inverter(latches[C]), Gates::inverter(latches[D])); break;
                case S1 :
                    state = Pins[S1] = Gates::_and(latches[A], Gates::inverter(latches[B]),
                                                   Gates::inverter(latches[C]), Gates::inverter(latches[D])); break;
                case S2 :
                    state = Pins[S2] = Gates::_and(Gates::inverter(latches[A]), latches[B],
                                                   Gates::inverter(latches[C]), Gates::inverter(latches[D])); break;
                case S3 :
                    state = Pins[S3] = Gates::_and(latches[A], latches[B],
                                                   Gates::inverter(latches[C]), Gates::inverter(latches[D])); break;
                case S4 :
                    state = Pins[S4] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                                   latches[C], Gates::inverter(latches[D])); break;
                case S5 :
                    state = Pins[S5] = Gates::_and(latches[A], Gates::inverter(latches[B]),
                                                   latches[C], Gates::inverter(latches[D])); break;
                case S6 :
                    state = Pins[S6] = Gates::_and(Gates::inverter(latches[A]), latches[B],
                                                   latches[C], Gates::inverter(latches[D])); break;
                case S7 :
                    state = Pins[S7] = Gates::_and(latches[A], latches[B],
                                                   latches[C], Gates::inverter(latches[D])); break;
                case S8 :
                    state = Pins[S8] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                                   Gates::inverter(latches[C]), latches[D]); break;
                case S9 :
                    state = Pins[S9] = Gates::_and(latches[A], Gates::inverter(latches[B]),
                                                   Gates::inverter(latches[C]), latches[D]); break;
                case S10 :
                    state = Pins[S10] = Gates::_and(Gates::inverter(latches[A]), latches[B],
                                                    Gates::inverter(latches[C]), latches[D]); break;
                case S11 :
                    state = Pins[S11] = Gates::_and(latches[A], latches[B],
                                                    Gates::inverter(latches[C]), latches[D]); break;
                case S12 :
                    state = Pins[S12] = Gates::_and(Gates::inverter(latches[A]), Gates::inverter(latches[B]),
                                                    latches[C], latches[D]); break;
                case S13 :
                    state = Pins[S13] = Gates::_and(latches[A], Gates::inverter(latches[B]),
                                                    latches[C], latches[D]); break;
                case S14 :
                    state = Pins[S14] = Gates::_and(Gates::inverter(latches[A]), latches[B],
                                                    latches[C], latches[D]); break;
                case S15 :
                    state = Pins[S15] = Gates::_and(latches[A], latches[B], latches[C], latches[D]); break;
                default:
                    state = UNDEFINED;
            }
        }
    }
    return (state);
}
