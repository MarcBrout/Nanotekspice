//
// Created by brout_m on 07/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTOUTPUT_HH
#define CPP_NANOTEKSPICE_COMPONENTOUTPUT_HH


#include <Component.hh>

namespace nts
{
    class ComponentOutput : public AComponent
    {
    public:
        ~ComponentOutput(){};
        ComponentOutput(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        ComponentOutput() = delete;
        ComponentOutput(ComponentOutput const& cmp) = delete;
        ComponentOutput &operator=(ComponentOutput const& cmp) = delete;
    };
}



#endif //CPP_NANOTEKSPICE_COMPONENTOUTPUT_HH
