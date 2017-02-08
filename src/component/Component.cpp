//
// Created by brout_m on 28/01/17.
//

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <map>
#include "Component.hh"

nts::AComponent::AComponent(std::string const& name,
                            nts::ComponentType type,
                            size_t nbPins,
                            std::vector<size_t> const& inputs,
                            std::vector<size_t> const& outputs,
                            std::vector<nts::Output> const& required) :
        Name(name),
        Type(type),
        Pins(nbPins, UNDEFINED),
        InPins(inputs),
        OutPins(outputs),
        Required(required)
{
}

std::string const &nts::AComponent::getName(void) const
{
  return Name;
}

bool nts::AComponent::setPin(size_t pin, nts::Tristate value)
{
  if (!isPinOk(pin))
    return false;
  Pins[pin] = value;
  return true;
}

std::ostream& operator<<(std::ostream &out, nts::Tristate state)
{
  out << (state == nts::UNDEFINED ? "undefined" : state == nts::TRUE ? "true" : "false");
  return (out);
}

void nts::AComponent::Dump(void) const
{
  std::cout << "Component : " << Type << " " << Name << "\n"
            << "ComponentInput pins :\n";

  if (!InPins.size())
    std::cout << "No input pin\n";
  else {
    std::cout << "Values :\n";
    for (size_t i = 0; i < InPins.size(); ++i) {
      std::cout << "Pin '" << InPins[i] << "' = " << Pins[InPins[i]] << "\n";
    }
    std::cout << "\nComponentInput links: \n";
    for (size_t i = 0; i < Inputs.size(); ++i)
    {
      std::cout << "Pin '" << Inputs[i].me << "' is linked to "
                << ComponentTypeString[static_cast<AComponent *>(Inputs[i].component)->Type] << " "
                << static_cast<AComponent *>(Inputs[i].component)->Name
                << "'s pin '" << Inputs[i].it << "\n";
    }
  }

  std::cout << "\nOutput pins:\n";
  if (!OutPins.size())
    std::cout << "No output pin\n";
  else
  {
    std::cout << "Values :\n";
    for (size_t i = 0; i < OutPins.size(); ++i) {
      std::cout << "Pin '" << OutPins[i] << "' = " << Pins[OutPins[i]] << "\n";
    }
    std::cout << "\nOutputs links: \n";
    for (size_t i = 0; i < Outputs.size(); ++i)
    {
      std::cout << "Pin '" << Outputs[i].me << "' is linked to "
                << ComponentTypeString[static_cast<AComponent *>(Outputs[i].component)->Type] << " "
                << static_cast<AComponent *>(Outputs[i].component)->Name
                << "'s pin '" << Outputs[i].it << "\n";
    }
  }
}

void nts::AComponent::SetLink(size_t pin_num_this, nts::IComponent &_component, size_t pin_num_target)
{
  AComponent &component = static_cast<AComponent &>(_component);
  bool inputPinThis = isInPinList(InPins, pin_num_this);
  bool inputPinIt = component.isInPinList(component.InPins, pin_num_target);

  if (!isPinOk(pin_num_this))
    throw std::logic_error(ComponentTypeString[Type] + " " + Name + "'s pin '" +
                           std::to_string(pin_num_this) + "' is out of range");
  if (!component.isPinOk(pin_num_target))
    throw std::logic_error("Target " + ComponentTypeString[component.getType()] + " " +
                           component.getName() + "'s pin '" +
                           std::to_string(pin_num_target) + "' is out of range");
  if (inputPinThis && inputPinIt)
    throw std::logic_error("Can't link " + ComponentTypeString[Type] + " " + Name +
                           "'s input pin '" + std::to_string(pin_num_this) +
                           "' to " + component.getName() + "'s input pin '" +
                           std::to_string(pin_num_target) +"'");
  if (!inputPinThis && !inputPinIt)
    throw std::logic_error("Can't link " + ComponentTypeString[Type] + " " + Name +
                           "'s output pin '" + std::to_string(pin_num_this) +
                           "' to " + ComponentTypeString[component.getType()] + " " +
                           component.getName() + "'s output pin '" +
                           std::to_string(pin_num_target) +"'");
  if (isPinAlreadyConnected(Inputs, pin_num_this))
    throw std::logic_error(ComponentTypeString[Type] + " " + Name +
                           "'s input pin already has a connexion");
  if (isPinAlreadyConnected(component.Inputs, pin_num_target))
    throw std::logic_error("Target " + ComponentTypeString[component.getType()] + " " +
                           component.getName() +
                           "'s input pin already has a connexion");

  if (inputPinThis)
    addLink(Inputs, pin_num_this, &_component, pin_num_target);
  else
    addLink(Outputs, pin_num_this, &_component, pin_num_target);

  if (inputPinIt)
    addLink(component.Inputs, pin_num_target, this, pin_num_this);
  else
    addLink(component.Outputs, pin_num_target, this, pin_num_this);
}

bool nts::AComponent::isPinOk(size_t pin) const
{
  return (pin && pin < Pins.size());
}

bool nts::AComponent::isInPinList(std::vector<size_t> const& pins, size_t pin) const
{
  return (std::find(pins.cbegin(), pins.cend(), pin) != pins.cend());
}

bool nts::AComponent::isPinAlreadyConnected(std::vector<nts::Link> const &links, size_t pin) const
{
  return (std::find(links.cbegin(), links.cend(), pin) != links.cend());
}

void nts::AComponent::addLink(std::vector<nts::Link> &links, size_t me, nts::IComponent *cmp, size_t it)
{
  Link link;

  link.me = me;
  link.component = cmp;
  link.it = it;
  links.push_back(link);
}

nts::Tristate nts::AComponent::getPinLinkedInput(size_t pin)
{
  std::vector<nts::Link>::iterator    it;
  AComponent                          *cmp;

  it = std::find(Inputs.begin(), Inputs.end(), pin);
  if (it != Inputs.end()) {
    cmp = static_cast<AComponent *>(it->component);
    if ((*cmp)[it->it] == UNDEFINED)
      Pins[pin] = cmp->Compute(it->it);
    return (Pins[pin]);
  }
  return (UNDEFINED);
}

nts::Tristate &nts::AComponent::operator[](size_t pin)
{
  if (!pin || pin >= Pins.size())
    throw std::logic_error("Pin out of range");
  return Pins[pin];
}

nts::ComponentType nts::AComponent::getType(void) const
{
  return Type;
}


/*
 * This function computes an Output Pin : pin_num_this.
 * It first searches its required input pins and try to compute them recursively if they're undefined
 * Depending of the input pin required it calls either the this->Compute or the Linked component Compute method
 */
nts::Tristate nts::AComponent::ComputeRequiredPins(size_t pin_num_this) {
  std::vector<nts::Output>::iterator  it;
  std::vector<nts::Link>::iterator    link;
  AComponent                          *cmp;

  it = std::find(Required.begin(), Required.end(), pin_num_this);
  if (it != Required.end())
  {
    for (std::vector<size_t>::iterator req = it->required.begin(); req != it->required.end(); req++)
    {
      if (Pins[*req] == UNDEFINED)
      {
        if (isInPinList(OutPins, *req))
        {
          Pins[*req] = this->Compute(*req);
        }
        else
        {
          link = std::find(Inputs.begin(), Inputs.end(), *req);
          if (link != Inputs.end()) {
            cmp = static_cast<AComponent *>(link->component);
            if ((*cmp)[link->it] == UNDEFINED) {
              Pins[*req] = cmp->Compute(link->it);
            } else {
              Pins[*req] = (*cmp)[link->it];
            }
          }
        }
      }
    }
    return (TRUE);
  }
  return (FALSE);
}

bool nts::s_link::operator==(size_t pin) const
{
  return (me == pin);
}

bool nts::s_output::operator==(size_t pin) const {
  return (me == pin);
}
