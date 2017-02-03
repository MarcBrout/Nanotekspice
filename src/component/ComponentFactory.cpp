//
// Created by brout_m on 28/01/17.
//

#include "ComponentFactory.hh"
#include "Component4001.hh"

nts::IComponent *nts::ComponentFactory::createComponent(std::string const &type, std::string const &value)
{
  std::map<std::string, nts::ComponentFactory::createCompPtr>::const_iterator cit;

  if (cmpBuilder.empty())
    cmpBuilder = createMap();

  cit = cmpBuilder.find(type);
  if (cit == cmpBuilder.end())
    return (NULL);
  return (this->*cmpBuilder[type](value));
}

std::map<std::string, nts::ComponentFactory::createCompPtr> nts::ComponentFactory::createMap() const
{
  std::map<std::string, nts::ComponentFactory::createCompPtr> map {
      {"4001", &create4001}
  };

}

nts::IComponent *nts::ComponentFactory::create4001(std::string const &value) const
{
  return (new Component4001(value));
}
