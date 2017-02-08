//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentFactory.hh"
#include "ComponentClock.hh"

int main() {
    nts::ComponentFactory   factory;
    nts::IComponent         *iCmpClock = factory.createComponent("clock", "TestingComponentClock");
    nts::AComponent         &aCmpClock = static_cast<nts::AComponent &>(*iCmpClock);

    std::cout << "Testing initial state of all pins";

    assert(aCmpClock.Compute(1) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all input gates";

    aCmpClock[1] = nts::TRUE;
    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::TRUE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    assert(aCmpClock.Compute(1) == nts::FALSE);
    aCmpClock.resetComputedPins();
    std::cout << ".";

    std::cout << "\nSuccess!\n";

    return (0);
}