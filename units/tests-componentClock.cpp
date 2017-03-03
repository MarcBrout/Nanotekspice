//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentClock.hh"

int main() {
    nts::ComponentClock aCmpClock("TestingClock");

    std::cout << "Testing initial state of all pins";

    assert(aCmpClock.Compute(1) == nts::FALSE);
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