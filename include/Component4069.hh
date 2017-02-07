//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4069_HH
#define CPP_NANOTEKSPICE_COMPONENT4069_HH

#include "Component.hh"

namespace nts
{
    class Component4069 : public AComponent
    {
    public:
        ~Component4069(){};
        Component4069(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4069() = delete;
        Component4069(Component4069 const& cmp) = delete;
        Component4069 &operator=(Component4069 const& cmp) = delete;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT4069_HH
