//
// Created by brout_m on 02/02/17.
//

#include "Component4001.hh"

nts::Component4001::Component4001()
{
  pins.resize(12);
}

nts::Tristate nts::Component4001::Compute(size_t pin_num_this)
{
  return nullptr;
}

void nts::Component4001::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{

}

void nts::Component4001::Dump(void) const
{

}