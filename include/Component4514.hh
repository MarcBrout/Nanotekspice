//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4514_HH
#define CPP_NANOTEKSPICE_COMPONENT4514_HH


#include "Component.hh"

namespace nts
{
    class Component4514 : public AComponent
    {
    public:
        enum LATCHES {
            A = 0,
            B,
            C,
            D
        };

        enum SELECTED {
            S0 = 11,
            S1 = 9,
            S2 = 10,
            S3 = 8,
            S4 = 7,
            S5 = 6,
            S6 = 5,
            S7 = 4,
            S8 = 18,
            S9 = 17,
            S10 = 20,
            S11 = 19,
            S12 = 14,
            S13 = 13,
            S14 = 16,
            S15 = 15
        };

        ~Component4514(){};
        Component4514(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);
        virtual void resetComputedPins(void);


    private:
        std::vector<nts::Tristate> latches;
        bool isComputed;
        Component4514() = delete;
        Component4514(Component4514 const& cmp) = delete;
        Component4514 &operator=(Component4514 const& cmp) = delete;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT4514_HH
