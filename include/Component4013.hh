//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4013_HH
#define CPP_NANOTEKSPICE_COMPONENT4013_HH

#include "Component.hh"

namespace nts {

    class Component4013 : public AComponent{

        enum PINS {
            KQ1 = 1,
            NQ1 = 2,
            CP1 = 3,
            RESET1 = 4,
            DATA1 = 5,
            SET1 = 6,
            SET2 = 8,
            DATA2 = 9,
            RESET2 = 10,
            CP2 = 11,
            NQ2 = 12,
            KQ2 = 13
        };

    public:
        ~Component4013() {};
        Component4013(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4013() = delete;
        Component4013(Component4013 const& cmp) = delete;
        Component4013 &operator=(Component4013 const &cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4013_HH
