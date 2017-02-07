//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4040_HH
#define CPP_NANOTEKSPICE_COMPONENT4040_HH

#include "Component.hh"

namespace nts {
    class Component4040 : public AComponent {
    public:
        ~Component4040() {};
        Component4040(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4040() = delete;
        Component4040(Component4040 const& cmp) = delete;
        Component4040 &operator=(Component4040 const &cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4040_HH
