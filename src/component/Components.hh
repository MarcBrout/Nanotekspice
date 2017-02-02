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
  typedef struct s_link Link;

  struct s_link
  {
    size_t        myPin;
    IComponent    *component;
    size_t        itsPin;
  };

  class AComponent : public IComponent
  {
  public:
    ~AComponent(){};
    AComponent();

  public:
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target) = 0;
    virtual void Dump(void) const = 0;

  protected:
    std::vector<nts::Tristate> pins;
    std::deque<nts::Link> links;

  private:
    AComponent(IComponent const& component);
    IComponent &operator=(IComponent const& component);
  };
}

#endif //CPP_NANOTEKSPICE_COMPONENTS_HH
