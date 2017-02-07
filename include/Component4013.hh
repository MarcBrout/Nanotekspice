//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4013_HH
#define CPP_NANOTEKSPICE_COMPONENT4013_HH

#include "Component.hh"

namespace nts {
    class Component4013 : public AComponent{
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
