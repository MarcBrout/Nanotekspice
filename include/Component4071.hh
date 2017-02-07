//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4071_HH
#define CPP_NANOTEKSPICE_COMPONENT4071_HH

#include "Component.hh"

namespace nts
{
    class Component4071 : public AComponent
    {
    public:
        ~Component4071() {};
        Component4071(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4071() = delete;
        Component4071(Component4071 const& cmp) = delete;
        Component4071 &operator=(Component4071 const &cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4071_HH
