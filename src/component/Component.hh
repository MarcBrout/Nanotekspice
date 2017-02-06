//
// Created by brout_m on 28/01/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENTS_HH
#define CPP_NANOTEKSPICE_COMPONENTS_HH

#include <deque>
#include <vector>
#include "IComponent.hh"

namespace nts
{
    enum ComponentType
    {
        COMPONENT4001 = 0,
        COMPONENT4011,
        COMPONENT4071,
        COMPONENT4081,
        COMPONENT4008,
        COMPONENT4013,
        COMPONENT4030,
        END_COMPONENT
    };

    static std::vector<std::string> ComponentTypeString {
            "4001",
            "4011",
            "4071",
            "4081",
            "4008",
            "4013",
            "4030"
    };

    typedef struct s_link Link;

    struct s_link
    {
        size_t        me;
        IComponent    *component;
        size_t        it;
        bool          operator==(size_t pin) const;
    };

    class AComponent : public IComponent
    {
    public:
        AComponent(std::string const &name, nts::ComponentType type, size_t nbPins, std::vector<size_t> const &inputs,
                   std::vector<size_t> const &outputs);
        virtual ~AComponent(){};

    public:
        virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
        virtual void SetLink(size_t pin_num_this, nts::IComponent& component, size_t pin_num_target);
        virtual void Dump(void) const;
        nts::ComponentType getType(void) const;
        std::string const &getName(void) const;
        bool setPin(size_t pin, nts::Tristate value);
        nts::Tristate& operator[](size_t pin);

    protected:
        std::string                 Name;
        nts::ComponentType          Type;
        std::vector<nts::Tristate>  Pins;
        std::vector<size_t>         InPins;
        std::vector<size_t>         OutPins;
        std::vector<nts::Link>      Outputs;
        std::vector<nts::Link>      Inputs;

    protected:
        AComponent(IComponent const& component) = delete;
        IComponent &operator=(IComponent const& component) = delete;
        bool isPinOk(size_t pin) const;
        bool isInPinList(std::vector<size_t> const& pins, size_t pin) const;
        bool isPinAlreadyConnected(std::vector<nts::Link> const& links, size_t pin) const;
        void addLink(std::vector<nts::Link> &links, size_t me, IComponent *cmp, size_t it);
        nts::Tristate getPinLinkedInput(size_t pin);
    };
}

std::ostream& operator<<(std::ostream &out, nts::Tristate state);

#endif //CPP_NANOTEKSPICE_COMPONENTS_HH
