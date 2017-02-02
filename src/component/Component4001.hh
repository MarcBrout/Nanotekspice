//
// Created by brout_m on 02/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4001_HH
#define CPP_NANOTEKSPICE_COMPONENT4001_HH

#include "Components.hh"

namespace nts
{

  class Component4001 : public AComponent
  {
  public:
    Component4001();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4001_HH
