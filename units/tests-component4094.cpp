//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentClock.hh"
#include "Component4094.hh"

int main() {
    nts::Component4094 aCmp4094("TestingComponent4094");
    nts::ComponentClock cp0("CP0");

    std::cout << "Testing initial state of all Pins";

    assert(aCmp4094[nts::Component4094::Q1] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q2] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q3] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q4] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q5] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q6] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q7] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q8] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::QS] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::NQS] == nts::UNDEFINED);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing 8-BIT Shift Register";

    cp0[1] = nts::TRUE;
    cp0.SetLink(1, aCmp4094, nts::Component4094::CP0);

    assert(aCmp4094[nts::Component4094::Q1] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q2] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q3] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q4] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q5] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q6] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q7] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q8] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::QS] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::NQS] == nts::UNDEFINED);

    cp0.resetComputedPins();
    std::cout << ".";
    std::cout << "\nSuccess!\n";
    return (0);
}