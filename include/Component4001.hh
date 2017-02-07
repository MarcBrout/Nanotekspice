//
// Created by brout_m on 02/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4001_HH
#define CPP_NANOTEKSPICE_COMPONENT4001_HH

#include "Component.hh"

namespace nts
{
  class Component4001 : public AComponent
  {
  public:
    ~Component4001(){};
    Component4001(std::string const& name);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

  private:
    Component4001() = delete;
    Component4001(Component4001 const& cmp) = delete;
    Component4001 &operator=(Component4001 const& cmp) = delete;
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4001_HH
