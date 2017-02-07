//
// Created by brout_m on 07/02/17.
//

#ifndef CPP_NANOTEKSPICE_INPUT_HH
#define CPP_NANOTEKSPICE_INPUT_HH

#include "Component.hh"

namespace nts
{
    class ComponentInput : public AComponent
    {
    public:
        ~ComponentInput(){};
        ComponentInput(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        ComponentInput() = delete;
        ComponentInput(ComponentInput const& cmp) = delete;
        ComponentInput &operator=(ComponentInput const& cmp) = delete;
    };
}


#endif //CPP_NANOTEKSPICE_INPUT_HH
