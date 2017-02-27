//
// Created by brout_m on 10/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4094_HH
#define CPP_NANOTEKSPICE_COMPONENT4094_HH


#include "Component.hh"

namespace nts
{
    class Component4094 : public AComponent
    {
    public:
        enum PINS {
            STROBE = 1,
            DATA = 2,
            CP0 = 3,
            Q1 = 4,
            Q2 = 5,
            Q3 = 6,
            Q4 = 7,
            QS = 9,
            NQS = 10,
            Q8 = 11,
            Q7 = 12,
            Q6 = 13,
            Q5 = 14,
            OUT = 15
        };
    public:
        ~Component4094(){};
        Component4094(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        uint8_t bit;
        bool    computed;
    private:
        Component4094() = delete;
        Component4094(Component4094 const& cmp) = delete;
        Component4094 &operator=(Component4094 const& cmp) = delete;
        virtual void resetComputedPins(void);
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT4094_HH
