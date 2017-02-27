//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4040_HH
#define CPP_NANOTEKSPICE_COMPONENT4040_HH

#include "Component.hh"

namespace nts {
    class Component4040 : public AComponent {
    public:
        enum PINS {
            CP0 = 10,
            RESET = 11,
            Q1 = 9,
            Q2 = 7,
            Q3 = 6,
            Q4 = 5,
            Q5 = 3,
            Q6 = 2,
            Q7 = 4,
            Q8 = 13,
            Q9 = 12,
            Q10 = 14,
            Q11 = 15,
            Q12 = 1
        };

    public:
        ~Component4040() {};
        Component4040(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);
        virtual void resetComputedPins(void);

    private:
        bool computed;

    private:
        Component4040() = delete;
        Component4040(Component4040 const& cmp) = delete;
        Component4040 &operator=(Component4040 const &cmp) = delete;
        void resetMe();
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4040_HH
