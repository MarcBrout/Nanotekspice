//
// Created by brout_m on 28/01/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTFACTORY_HH
#define CPP_NANOTEKSPICE_COMPONENTFACTORY_HH

#include <string>
#include <map>
#include "IComponent.hh"

namespace nts
{
    class BluePrint
    {
    public:
        nts::IComponent* create4001(std::string const& value);
        nts::IComponent* create4008(std::string const& value);
        nts::IComponent* create4011(std::string const& value);
        nts::IComponent* create4071(std::string const& value);
        nts::IComponent* create4081(std::string const& value);
        nts::IComponent* create4013(std::string const& value);
        nts::IComponent* create4030(std::string const& value);
        nts::IComponent* create4017(std::string const& value);
        nts::IComponent* create4040(std::string const& value);
        nts::IComponent* create4069(std::string const& value);
        nts::IComponent* create4094(std::string const& value);
        nts::IComponent* create4503(std::string const& value);
        nts::IComponent* create4512(std::string const& value);
        nts::IComponent* create4514(std::string const& value);
        nts::IComponent* create4801(std::string const& value);
        nts::IComponent* createInput(std::string const& value);
        nts::IComponent* createOutput(std::string const& value);
        nts::IComponent *createClock(std::string const& value);
        nts::IComponent* createFalse(std::string const& value);
        nts::IComponent *createTrue(std::string const& value);
    };

    class ComponentFactory
    {
    public:
        typedef nts::IComponent* (nts::BluePrint::*createCompPtr)(std::string const& value);
        nts::IComponent* createComponent(std::string const& type, std::string const& value);

    private:
        std::map<const std::string, createCompPtr> createMap();
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENTFACTORY_HH
