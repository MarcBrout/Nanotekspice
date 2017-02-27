//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4017_HH
#define CPP_NANOTEKSPICE_COMPONENT4017_HH

#include "Component.hh"

namespace nts {

    class Component4017 : public AComponent {
    public:
        enum PINS
        {
            Q5 = 1,
            Q1 = 2,
            Q0 = 3,
            Q2 = 4,
            Q6 = 5,
            Q7 = 6,
            Q3 = 7,
            Q8 = 9,
            Q4 = 10,
            Q9 = 11,
            Q59 = 12,
            CP1 = 13,
            CP0 = 14,
            MR = 15
        };

    public:
        ~Component4017() {};
        Component4017(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);
        virtual void resetComputedPins(void);

    private:
        bool cp0State;
        bool computedOnce;
        Component4017() = delete;
        Component4017(Component4017 const& cmp) = delete;
        Component4017 &operator=(Component4017 const &cmp) = delete;
        void resetMe();
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4017_HH
