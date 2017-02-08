//
// Created by brout_m on 08/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTTRUE_HH
#define CPP_NANOTEKSPICE_COMPONENTTRUE_HH

#include "Component.hh"

namespace nts
{
    class ComponentTrue : public AComponent
    {
    public:
        ~ComponentTrue(){};
        ComponentTrue(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        ComponentTrue() = delete;
        ComponentTrue(ComponentTrue const& cmp) = delete;
        ComponentTrue &operator=(ComponentTrue const& cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENTTRUE_HH
