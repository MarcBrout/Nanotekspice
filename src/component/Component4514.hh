//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4514_HH
#define CPP_NANOTEKSPICE_COMPONENT4514_HH


#include "Component.hh"

namespace nts
{
    class Component4514 : public AComponent
    {
    public:
        ~Component4514(){};
        Component4514(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        std::vector<nts::Tristate> latches;
        Component4514() = delete;
        Component4514(Component4514 const& cmp) = delete;
        Component4514 &operator=(Component4514 const& cmp) = delete;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT4514_HH
