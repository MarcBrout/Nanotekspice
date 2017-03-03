//
// Created by brout_m on 06/02/17.
//

#include <algorithm>
#include <stdexcept>
#include "Component4801.hh"
#include "Gates.hh"

nts::Component4801::Component4801(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4801,
                   24,
                   {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE},
                   {DQ0, DQ1, DQ2, DQ3, DQ4, DQ5, DQ6, DQ7},
                   {{DQ0, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ1, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ2, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ3, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ4, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ5, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ6, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}},
                    {DQ7, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, WE, OE, CE}}
                   }),
        ram(1024, 0)
{
}

nts::Tristate nts::Component4801::Compute(size_t pin_num_this)
{
    nts::Tristate   state;
    size_t          x;
    size_t          y;
    char            c;

    if (!isPinOk(pin_num_this))
        throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

    if (isInPinList(InPins, pin_num_this)) {
        state = getPinLinkedInput(pin_num_this);
    } else {
        ComputeRequiredPins(pin_num_this);

        x = y = 0x0;
        c = 0;
        if (Pins[CE] == TRUE) {
            y += Pins[A1] == TRUE ? 0x001 : 0x0;
            y += Pins[A6] == TRUE ? 0x010 : 0x0;
            y += Pins[A8] == TRUE ? 0x100 : 0x0;

            x += Pins[A0] == TRUE ? 0x0000001 : 0x0;
            x += Pins[A2] == TRUE ? 0x0000010 : 0x0;
            x += Pins[A3] == TRUE ? 0x0000100 : 0x0;
            x += Pins[A4] == TRUE ? 0x0001000 : 0x0;
            x += Pins[A5] == TRUE ? 0x0010000 : 0x0;
            x += Pins[A7] == TRUE ? 0x0100000 : 0x0;
            x += Pins[A9] == TRUE ? 0x1000000 : 0x0;

            if (Pins[WE] == TRUE) {
                Compute(DQ0);
                Compute(DQ1);
                Compute(DQ2);
                Compute(DQ3);
                Compute(DQ4);
                Compute(DQ5);
                Compute(DQ6);
                Compute(DQ7);

                c += Pins[DQ0] == TRUE ? 0x00000001 : 0x0;
                c += Pins[DQ1] == TRUE ? 0x00000010 : 0x0;
                c += Pins[DQ2] == TRUE ? 0x00000100 : 0x0;
                c += Pins[DQ3] == TRUE ? 0x00001000 : 0x0;
                c += Pins[DQ4] == TRUE ? 0x00010000 : 0x0;
                c += Pins[DQ5] == TRUE ? 0x00100000 : 0x0;
                c += Pins[DQ6] == TRUE ? 0x01000000 : 0x0;
                c += Pins[DQ7] == TRUE ? 0x10000000 : 0x0;

                ram[x + y * 128] = c;

                state = Pins[pin_num_this];
            } else if (Pins[OE] == TRUE) {
                char    r;

                r = ram[x + y * 128];

                Pins[DQ0] = r & 0x00000001 ? TRUE : FALSE;
                Pins[DQ1] = r & 0x00000010 ? TRUE : FALSE;
                Pins[DQ2] = r & 0x00000100 ? TRUE : FALSE;
                Pins[DQ3] = r & 0x00001000 ? TRUE : FALSE;
                Pins[DQ4] = r & 0x00010000 ? TRUE : FALSE;
                Pins[DQ5] = r & 0x00100000 ? TRUE : FALSE;
                Pins[DQ6] = r & 0x01000000 ? TRUE : FALSE;
                Pins[DQ7] = r & 0x10000000 ? TRUE : FALSE;

                state = Pins[pin_num_this];
            } else {
                state = UNDEFINED;
            }
        } else {
            state = UNDEFINED;
        }
    }
    return (state);
}

nts::Component4801::~Component4801() {
}
