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
    class ComponentFactory
    {
    public:
        typedef IComponent* (ComponentFactory::*createCompPtr)(std::string const& value);
        IComponent* createComponent(std::string const& type, std::string const& value);

    private:
        static std::map<std::string, nts::ComponentFactory::createCompPtr> cmpBuilder;
        std::map<std::string, nts::ComponentFactory::createCompPtr> createMap() const;
        IComponent* create4001(std::string const& value) const;
        IComponent* create4011(std::string const& value) const;
        IComponent* create4071(std::string const& value) const;
        IComponent* create4081(std::string const& value) const;
        IComponent* create4013(std::string const& value) const;
        IComponent* create4030(std::string const& value) const;
    };
}

#endif //CPP_NANOTEKSPICE_COMPONENTFACTORY_HH
