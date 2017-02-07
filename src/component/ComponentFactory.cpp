//
// Created by brout_m on 28/01/17.
//

#include "../../include/ComponentFactory.hh"
#include "../../include/Component4001.hh"
#include "../../include/Component4011.hh"
#include "../../include/Component4071.hh"
#include "../../include/Component4081.hh"
#include "../../include/Component4013.hh"
#include "../../include/Component4030.hh"
#include "../../include/Component4017.hh"
#include "../../include/Component4040.hh"
#include "../../include/Component4069.hh"
#include "../../include/Component4514.hh"

nts::IComponent *nts::ComponentFactory::createComponent(std::string const &type, std::string const &value)
{
    static std::map<const std::string, nts::ComponentFactory::createCompPtr> cmpBuilder = createMap();
    std::map<const std::string, nts::ComponentFactory::createCompPtr>::const_iterator cit;
    BluePrint bluePrint;

    if (cmpBuilder.empty())
        cmpBuilder = createMap();

    cit = cmpBuilder.find(type);
    if (cit == cmpBuilder.end())
        return (NULL);
    return (bluePrint.*cmpBuilder[type])(value);
}

std::map<const std::string, nts::ComponentFactory::createCompPtr> nts::ComponentFactory::createMap()
{
    std::map<const std::string, nts::ComponentFactory::createCompPtr> map;

    map["4001"] = &nts::BluePrint::create4001;
    map["4011"] = &nts::BluePrint::create4011;
    map["4071"] = &nts::BluePrint::create4071;
    map["4081"] = &nts::BluePrint::create4081;
    map["4013"] = &nts::BluePrint::create4013;
    map["4030"] = &nts::BluePrint::create4030;
    map["4017"] = &nts::BluePrint::create4017;
    map["4040"] = &nts::BluePrint::create4040;
    map["4069"] = &nts::BluePrint::create4069;
    map["4514"] = &nts::BluePrint::create4514;
    return (map);
}

nts::IComponent *nts::BluePrint::create4001(std::string const &value)
{
    return (new Component4001(value));
}

nts::IComponent *nts::BluePrint::create4011(std::string const &value)
{
    return (new Component4011(value));
}

nts::IComponent *nts::BluePrint::create4071(std::string const &value)
{
    return (new Component4071(value));
}

nts::IComponent *nts::BluePrint::create4081(std::string const &value)
{
    return (new Component4081(value));
}

nts::IComponent *nts::BluePrint::create4013(std::string const &value)
{
    return (new Component4013(value));
}

nts::IComponent *nts::BluePrint::create4030(std::string const &value)
{
    return (new Component4030(value));
}

nts::IComponent *nts::BluePrint::create4017(std::string const &value)
{
    return (new Component4017(value));
}

nts::IComponent *nts::BluePrint::create4040(std::string const &value)
{
    return (new Component4040(value));
}

nts::IComponent *nts::BluePrint::create4069(std::string const &value)
{
    return (new Component4069(value));
}

nts::IComponent *nts::BluePrint::create4514(std::string const &value)
{
    return (new Component4514(value));
}
