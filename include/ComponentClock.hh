//
// Created by brout_m on 08/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTCLOCK_HH
#define CPP_NANOTEKSPICE_COMPONENTCLOCK_HH

#include "Component.hh"

namespace nts
{
    class ComponentClock : public AComponent
    {
    public:
        ~ComponentClock(){};
        ComponentClock(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);
        virtual void resetComputedPins(void);

    private:
        bool Reset;
        ComponentClock() = delete;
        ComponentClock(ComponentClock const& cmp) = delete;
        ComponentClock &operator=(ComponentClock const& cmp) = delete;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENTCLOCK_HH
