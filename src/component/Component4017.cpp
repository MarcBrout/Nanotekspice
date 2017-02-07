//
// Created by brout_m on 06/02/17.
//

#include <stdexcept>
#include "Gates.hh"
#include "Component4017.hh"

nts::Component4017::Component4017(std::string const &name) :
        AComponent(name,
                   nts::COMPONENT4017,
                   16,
                   {13, 14, 15},
                   {3, 2, 4, 7, 10, 1, 5, 6, 9, 11, 12},
                   {{3, {13, 14, 15}},
                    {2, {13, 14, 15}},
                    {4, {13, 14, 15}},
                    {7, {13, 14, 15}},
                    {10, {13, 14, 15}},
                    {1, {13, 14, 15}},
                    {5, {13, 14, 15}},
                    {6, {13, 14, 15}},
                    {9, {13, 14, 15}},
                    {11, {13, 14, 15}},
                    {12, {13, 14, 15}},
                   })
{
}

nts::Tristate nts::Component4017::Compute(size_t pin_num_this)
{

    /* /!\ NOT DONE /!\ */
    nts::Tristate state;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        switch (pin_num_this) {
            case 3 : state = Pins[3] = Gates::nor(Pins[1], Pins[2]); break;
            case 4 : state = Pins[4] = Gates::nor(Pins[5], Pins[6]); break;
            case 10 : state = Pins[10] = Gates::nor(Pins[8], Pins[9]); break;
            case 11 : state = Pins[11] = Gates::nor(Pins[12], Pins[13]); break;
            default: state = UNDEFINED;
        }
    }
    return (state);
}
