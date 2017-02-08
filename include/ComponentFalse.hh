//
// Created by brout_m on 08/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFALSE_HH
#define CPP_NANOTEKSPICE_COMPONENTFALSE_HH

#include "Component.hh"

namespace nts
{
    class ComponentFalse : public AComponent
    {
    public:
        ~ComponentFalse(){};
        ComponentFalse(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        ComponentFalse() = delete;
        ComponentFalse(ComponentFalse const& cmp) = delete;
        ComponentFalse &operator=(ComponentFalse const& cmp) = delete;
    };
}
#endif //CPP_NANOTEKSPICE_COMPONENTFALSE_HH
