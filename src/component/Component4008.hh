//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4008_HH
#define CPP_NANOTEKSPICE_COMPONENT4008_HH

#include "Component.hh"

namespace nts 
{
    class Component4008 : public AComponent 
    {
    public:
        ~Component4008(){};
        Component4008(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4008() = delete;
        Component4008(Component4008 const& cmp) = delete;
        Component4008 &operator=(Component4008 const& cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4008_HH
