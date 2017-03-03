//
// Created by brout_m on 10/02/17.
//


#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Component2716.hh"
#include "Gates.hh"

nts::Component2716::Component2716(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT2716,
                   24,
                   {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM},
                   {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7},
                   {{Q0, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q1, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q2, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q3, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q4, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q5, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q6, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}},
                    {Q7, {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, G, PGM}}
                   })
{
}

nts::Tristate nts::Component2716::Compute(size_t pin_num_this)
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
        if (Pins[G] == TRUE) {
            y += Pins[A0] == TRUE ? 0x0001 : 0x0;
            y += Pins[A1] == TRUE ? 0x0010 : 0x0;
            y += Pins[A2] == TRUE ? 0x0100 : 0x0;
            y += Pins[A3] == TRUE ? 0x1000 : 0x0;

            x += Pins[A4] == TRUE ? 0x0000001 : 0x0;
            x += Pins[A5] == TRUE ? 0x0000010 : 0x0;
            x += Pins[A6] == TRUE ? 0x0000100 : 0x0;
            x += Pins[A7] == TRUE ? 0x0001000 : 0x0;
            x += Pins[A8] == TRUE ? 0x0010000 : 0x0;
            x += Pins[A9] == TRUE ? 0x0100000 : 0x0;
            x += Pins[A10] == TRUE ? 0x1000000 : 0x0;

            if (x + y * 256 < rom.size())
                c = rom[x + y * 256];

            Pins[Q0] = c & 0x00000001 ? TRUE : FALSE;
            Pins[Q1] = c & 0x00000010 ? TRUE : FALSE;
            Pins[Q2] = c & 0x00000100 ? TRUE : FALSE;
            Pins[Q3] = c & 0x00001000 ? TRUE : FALSE;
            Pins[Q4] = c & 0x00010000 ? TRUE : FALSE;
            Pins[Q5] = c & 0x00100000 ? TRUE : FALSE;
            Pins[Q6] = c & 0x01000000 ? TRUE : FALSE;
            Pins[Q7] = c & 0x10000000 ? TRUE : FALSE;

            state = Pins[pin_num_this];
        } else {
            state = UNDEFINED;
        }
    }
    return (state);
}

bool nts::Component2716::feedRom(std::string const &filename) {
    std::ifstream ifs(filename);

    if (!ifs.is_open() || ifs.gcount() == 0)
        return (true);
    rom.assign((std::istreambuf_iterator<char>(ifs)),
               (std::istreambuf_iterator<char>()));
    ifs.close();
    return (false);
}

