//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_Component4081_HH
#define CPP_NANOTEKSPICE_Component4081_HH

#include "Component.hh"

namespace nts 
{
    class Component4081 : public AComponent 
    {
    public:
        ~Component4081() {};
        Component4081(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4081() = delete;
        Component4081(Component4081 const& cmp) = delete;
        Component4081 &operator=(Component4081 const &cmp) = delete;
    };
}

#endif //CPP_NANOTEKSPICE_Component4081_HH
