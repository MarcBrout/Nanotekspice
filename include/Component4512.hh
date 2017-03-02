//
// Created by brout_m on 02/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4512_HH
#define CPP_NANOTEKSPICE_COMPONENT4512_HH

#include "Component.hh"

namespace nts
{
  class Component4512 : public AComponent
  {
  public:
      enum PINS {
          X0 = 1,
          X1 = 2,
          X2 = 3,
          X3 = 4,
          X4 = 5,
          X5 = 6,
          X6 = 7,
          X7 = 9,
          INHIB = 10,
          A = 11,
          B = 12,
          C = 13,
          Z = 14,
          OE = 15

      };
  public:
    ~Component4512(){};
    Component4512(std::string const& name);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

  private:
    Component4512() = delete;
    Component4512(Component4512 const& cmp) = delete;
    Component4512 &operator=(Component4512 const& cmp) = delete;
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4512_HH
