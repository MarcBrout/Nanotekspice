//
// Created by brout_m on 02/02/17.
//

#include <algorithm>
#include <stdexcept>
#include "Component4503.hh"
#include "Gates.hh"

nts::Component4503::Component4503(std::string const& name) :
        AComponent(name,
                   nts::COMPONENT4503,
                   16,
                   {IN1, IN2, IN3, IN4, IN5, IN6, DIS1, DIS2},
                   {OUT1, OUT2, OUT3, OUT4, OUT5, OUT6},
                   {{OUT1, {IN1, DIS1}},
                    {OUT2, {IN2, DIS1}},
                    {OUT3, {IN3, DIS1}},
                    {OUT4, {IN4, DIS1}},
                    {OUT5, {IN5, DIS2}},
                    {OUT6, {IN6, DIS2}}
                   })
{
}

nts::Tristate nts::Component4503::Compute(size_t pin_num_this)
{
  nts::Tristate                       state;
  std::vector<nts::Output>::iterator  it;

  if (!isPinOk(pin_num_this))
    throw std::logic_error(Name + " doesn't have a '" + std::to_string(pin_num_this) + "' pin");

  if (isInPinList(InPins, pin_num_this)) {
    state = getPinLinkedInput(pin_num_this);
  } else {
    ComputeRequiredPins(pin_num_this);
    it = std::find(Required.begin(), Required.end(), pin_num_this);
    if (it != Required.end()) {
        state = Pins[pin_num_this] = Pins[it->required[1]] == TRUE ? UNDEFINED : Pins[it->required[0]];
    }
    else
      state = UNDEFINED;
  }
  return (state);
}
