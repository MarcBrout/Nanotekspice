//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include <algorithm>
#include "../../include/Component4040.hh"
#include "../../include/Gates.hh"

nts::Component4040::Component4040(std::string const &name) :
    AComponent(name,
               nts::COMPONENT4040,
               16,
               {10, 11},
               {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1},
               {{9, {10, 11, 10}},
                {7, {10, 11, 9}},
                {6, {10, 11, 7}},
                {5, {10, 11, 6}},
                {3, {10, 11, 5}},
                {2, {10, 11, 3}},
                {4, {10, 11, 2}},
                {13, {10, 11, 4}},
                {12, {10, 11, 13}},
                {14, {10, 11, 12}},
                {15, {10, 11, 14}},
                {1, {10, 11, 15}}
               })
{
}

nts::Tristate nts::Component4040::Compute(size_t pin_num_this) {
    static size_t pos = 1;
    nts::Tristate state;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        if (Pins[11] == TRUE)
        {
            std::for_each(Pins.begin(), Pins.end(), [](nts::Tristate &x){ x = FALSE; });
            pos = 1;
            state = FALSE;
        }
        else if (Pins[10] == FALSE && pos <= OutPins.size())
        {
            if (pos > 1)
                Pins[OutPins[pos - 2]] = FALSE;
            Pins[OutPins[pos - 1]] = TRUE;
            state = Pins[pin_num_this];
        }
        else
            state = UNDEFINED;
    }
    return (state);
}
