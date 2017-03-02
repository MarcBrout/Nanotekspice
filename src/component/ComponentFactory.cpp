//
// Created by brout_m on 28/01/17.
//

#include "ComponentFactory.hh"
#include "Component4001.hh"
#include "Component4008.hh"
#include "Component4011.hh"
#include "Component4071.hh"
#include "Component4081.hh"
#include "Component4013.hh"
#include "Component4030.hh"
#include "Component4017.hh"
#include "Component4040.hh"
#include "Component4069.hh"
#include "Component4094.hh"
#include "Component4512.hh"
#include "Component4514.hh"
#include "Component4503.hh"
#include "ComponentInput.hh"
#include "ComponentOutput.hh"
#include "ComponentClock.hh"
#include "ComponentTrue.hh"
#include "ComponentFalse.hh"

nts::IComponent *nts::ComponentFactory::createComponent(std::string const &type, std::string const &value)
{
    static std::map<const std::string, nts::ComponentFactory::createCompPtr> cmpBuilder = createMap();
    std::map<const std::string, nts::ComponentFactory::createCompPtr>::const_iterator cit;
    BluePrint bluePrint;

    if (cmpBuilder.empty())
        cmpBuilder = createMap();

    cit = cmpBuilder.find(type);
    if (cit == cmpBuilder.end())
        return (nullptr);
    return (bluePrint.*cmpBuilder[type])(value);
}

std::map<const std::string, nts::ComponentFactory::createCompPtr> nts::ComponentFactory::createMap()
{
    std::map<const std::string, nts::ComponentFactory::createCompPtr> map;

    map["4001"] = &nts::BluePrint::create4001;
    map["4008"] = &nts::BluePrint::create4008;
    map["4011"] = &nts::BluePrint::create4011;
    map["4071"] = &nts::BluePrint::create4071;
    map["4081"] = &nts::BluePrint::create4081;
    map["4013"] = &nts::BluePrint::create4013;
    map["4030"] = &nts::BluePrint::create4030;
    map["4017"] = &nts::BluePrint::create4017;
    map["4040"] = &nts::BluePrint::create4040;
    map["4069"] = &nts::BluePrint::create4069;
    map["4094"] = &nts::BluePrint::create4094;
    map["4503"] = &nts::BluePrint::create4503;
    map["4512"] = &nts::BluePrint::create4512;
    map["4514"] = &nts::BluePrint::create4514;
    map["input"] = &nts::BluePrint::createInput;
    map["output"] = &nts::BluePrint::createOutput;
    map["clock"] = &nts::BluePrint::createClock;
    map["false"] = &nts::BluePrint::createFalse;
    map["true"] = &nts::BluePrint::createTrue;

    return (map);
}

nts::IComponent *nts::BluePrint::create4001(std::string const &value) {
    return (new Component4001(value));
}

nts::IComponent *nts::BluePrint::create4008(std::string const &value) {
    return (new Component4008(value));
}

nts::IComponent *nts::BluePrint::create4011(std::string const &value) {
    return (new Component4011(value));
}

nts::IComponent *nts::BluePrint::create4071(std::string const &value) {
    return (new Component4071(value));
}

nts::IComponent *nts::BluePrint::create4081(std::string const &value) {
    return (new Component4081(value));
}

nts::IComponent *nts::BluePrint::create4013(std::string const &value) {
    return (new Component4013(value));
}

nts::IComponent *nts::BluePrint::create4030(std::string const &value) {
    return (new Component4030(value));
}

nts::IComponent *nts::BluePrint::create4017(std::string const &value) {
    return (new Component4017(value));
}

nts::IComponent *nts::BluePrint::create4040(std::string const &value) {
    return (new Component4040(value));
}

nts::IComponent *nts::BluePrint::create4069(std::string const &value) {
    return (new Component4069(value));
}

nts::IComponent *nts::BluePrint::create4094(std::string const &value) {
    return (new Component4094(value));
}

nts::IComponent *nts::BluePrint::create4512(std::string const &value) {
    return (new Component4512(value));
}

nts::IComponent *nts::BluePrint::create4514(std::string const &value) {
    return (new Component4514(value));
}

nts::IComponent *nts::BluePrint::create4503(std::string const &value) {
    return (new Component4503(value));
}

nts::IComponent *nts::BluePrint::createInput(std::string const &value) {
    return (new ComponentInput(value));
}

nts::IComponent *nts::BluePrint::createOutput(std::string const &value) {
    return (new ComponentOutput(value));
}

nts::IComponent *nts::BluePrint::createClock(std::string const &value) {
    return (new ComponentClock(value));
}

nts::IComponent *nts::BluePrint::createFalse(std::string const &value) {
    return (new ComponentFalse(value));
}

nts::IComponent *nts::BluePrint::createTrue(std::string const &value) {
    return (new ComponentTrue(value));
}
