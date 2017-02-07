//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4011_H
#define CPP_NANOTEKSPICE_COMPONENT4011_H

#include "Component.hh"

namespace nts
{
    class Component4011 : public AComponent
    {
    public:
        ~Component4011(){};
        Component4011(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4011() = delete;
        Component4011(Component4011 const& cmp) = delete;
        Component4011 &operator=(Component4011 const& cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4011_H
