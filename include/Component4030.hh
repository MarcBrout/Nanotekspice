//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4030_HH
#define CPP_NANOTEKSPICE_COMPONENT4030_HH


#include "Component.hh"

namespace nts
{
    class Component4030 : public AComponent
    {
    public:
        ~Component4030(){};
        Component4030(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4030() = delete;
        Component4030(Component4030 const& cmp) = delete;
        Component4030 &operator=(Component4030 const& cmp) = delete;

    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4030_HH
