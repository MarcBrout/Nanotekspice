//
// Created by brout_m on 02/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4503_HH
#define CPP_NANOTEKSPICE_COMPONENT4503_HH

#include "Component.hh"

namespace nts
{
  class Component4503 : public AComponent
  {
  public:
      enum PINS {
          DIS1 = 1,
          IN1 = 2,
          OUT1 = 3,
          IN2 = 4,
          OUT2 = 5,
          IN3 = 6,
          OUT3 = 7,
          OUT4 = 9,
          IN4 = 10,
          OUT5 = 11,
          IN5 = 12,
          OUT6 = 13,
          IN6 = 14,
          DIS2 = 15
      };

  public:
    ~Component4503(){};
    Component4503(std::string const& name);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);

  private:
    Component4503() = delete;
    Component4503(Component4503 const& cmp) = delete;
    Component4503 &operator=(Component4503 const& cmp) = delete;
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENT4503_HH
