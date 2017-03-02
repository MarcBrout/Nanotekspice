//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4503.hh"

int main() {
    nts::Component4503 aCmp4503("TestingComponent4503");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 15; ++i) {
        assert(aCmp4503[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4503.Compute(nts::Component4503::OUT1) == nts::UNDEFINED);
    assert(aCmp4503.Compute(nts::Component4503::OUT2) == nts::UNDEFINED);
    assert(aCmp4503.Compute(nts::Component4503::OUT3) == nts::UNDEFINED);
    assert(aCmp4503.Compute(nts::Component4503::OUT4) == nts::UNDEFINED);
    assert(aCmp4503.Compute(nts::Component4503::OUT5) == nts::UNDEFINED);
    assert(aCmp4503.Compute(nts::Component4503::OUT6) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all Buffer gates";

    aCmp4503[nts::Component4503::IN1] = nts::TRUE;
    aCmp4503[nts::Component4503::DIS1] = nts::FALSE;
    assert(aCmp4503.Compute(nts::Component4503::OUT1) == nts::TRUE);
    std::cout << ".";

    aCmp4503[nts::Component4503::IN1] = nts::FALSE;
    aCmp4503[nts::Component4503::DIS1] = nts::FALSE;
    assert(aCmp4503.Compute(nts::Component4503::OUT1) == nts::FALSE);
    std::cout << ".";

    aCmp4503[nts::Component4503::IN1] = nts::TRUE;
    aCmp4503[nts::Component4503::DIS1] = nts::TRUE;
    assert(aCmp4503.Compute(nts::Component4503::OUT1) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nSuccess!\n";

    return (0);
}