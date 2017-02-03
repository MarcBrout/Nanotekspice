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
    ~Component4001(){};
    Component4001(std::string const& name);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

  private:

    nts::Tristate nor_gate(nts::Tristate in1, nts::Tristate in2);
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4001_HH
