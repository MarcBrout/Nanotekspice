//
// Created by brout_m on 28/01/17.
//

#include "ComponentFactory.hh"
#include "Component4001.hh"
#include "Component4011.h"
#include "Component4071.hh"
#include "Component4081.hh"
#include "Component4013.hh"

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
            {"4001", &create4001},
            {"4011", &create4011},
            {"4071", &create4071},
            {"4081", &create4081},
            {"4013", &create4013},
            {"4030", &create4030}

    };
    return (map);
}

nts::IComponent *nts::ComponentFactory::create4001(std::string const &value) const
{
    return (new Component4001(value));
}

nts::IComponent *nts::ComponentFactory::create4011(std::string const &value) const
{
    return (new Component4011(value));
}

nts::IComponent *nts::ComponentFactory::create4071(std::string const &value) const
{
    return (new Component4071(value));
}

nts::IComponent *nts::ComponentFactory::create4081(std::string const &value) const
{
    return (new Component4081(value));
}

nts::IComponent *nts::ComponentFactory::create4013(std::string const &value) const
{
    return (new Component4013(value));
}

nts::IComponent *nts::ComponentFactory::create4030(std::string const &value) const
{
    return (new Component4030(value));
}
