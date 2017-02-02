//
// Created by brout_m on 28/01/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFACTORY_HH
#define CPP_NANOTEKSPICE_COMPONENTFACTORY_HH

#include <string>
#include "IComponent.hh"

namespace nts
{
  class ComponentFactory
  {
  public:
    typedef IComponent* (IComponent::*createCompPtr)(std::string const& value);
    IComponent* createComponent(std::string const& type, std::string const& value);

  private:

  };
}

#endif //CPP_NANOTEKSPICE_COMPONENTFACTORY_HH
