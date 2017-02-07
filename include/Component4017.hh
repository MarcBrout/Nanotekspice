//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4017_HH
#define CPP_NANOTEKSPICE_COMPONENT4017_HH

#include "Component.hh"

namespace nts {

    class Component4017 : public AComponent {
    public:
        ~Component4017() {};
        Component4017(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4017() = delete;
        Component4017(Component4017 const& cmp) = delete;
        Component4017 &operator=(Component4017 const &cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4017_HH
