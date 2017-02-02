//
// Created by brout_m on 28/01/17.
//

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HH
#define CPP_NANOTEKSPICE_ICOMPONENT_HH

#include <cstddef>

namespace nts
{
  enum Tristate
  {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
  };

  class IComponent
  {
  public:
    virtual ~IComponent(void){};
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target) = 0;
    virtual void Dump(void) const = 0;
    virtual void setName(std::string const& name) = 0;
    virtual std::string const& getName(void) const = 0;
    virtual bool setPin(size_t pin, nts::Tristate value) = 0;
  };
}

#endif //CPP_NANOTEKSPICE_ICOMPONENT_HH
