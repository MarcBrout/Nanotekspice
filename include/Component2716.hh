//
// Created by brout_m on 10/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT2716_HH
#define CPP_NANOTEKSPICE_COMPONENT2716_HH


#include "Component.hh"

namespace nts
{
    class Component2716 : public AComponent
    {
    public:
    enum PINS {
        A0 = 8,
        A1 = 7,
        A2 = 6,
        A3 = 5,
        A4 = 4,
        A5 = 3,
        A6 = 2,
        A7 = 1,
        A8 = 23,
        A9 = 22,
        A10 = 19,
        Q0 = 9,
        Q1 = 10,
        Q2 = 11,
        Q3 = 13,
        Q4 = 14,
        Q5 = 15,
        Q6 = 16,
        Q7 = 17,
        G = 20,
        PGM = 18,
    };

    public:
        ~Component2716(){};
        Component2716(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);
        bool feedRom(std::string const& filename);

    private:
        Component2716() = delete;
        Component2716(Component2716 const& cmp) = delete;
        Component2716 &operator=(Component2716 const& cmp) = delete;
        std::string rom;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT2716_HH
