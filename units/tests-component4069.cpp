//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4069.hh"

int main() {
    nts::Component4069 aCmp4069("TestingComponent4069");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4069[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4069.Compute(2) == nts::UNDEFINED);
    assert(aCmp4069.Compute(4) == nts::UNDEFINED);
    assert(aCmp4069.Compute(6) == nts::UNDEFINED);
    assert(aCmp4069.Compute(8) == nts::UNDEFINED);
    assert(aCmp4069.Compute(10) == nts::UNDEFINED);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all inverter gates";

    aCmp4069[1] = nts::TRUE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::UNDEFINED);
    assert(aCmp4069.Compute(6) == nts::UNDEFINED);
    assert(aCmp4069.Compute(8) == nts::UNDEFINED);
    assert(aCmp4069.Compute(10) == nts::UNDEFINED);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4069[3] = nts::FALSE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::TRUE);
    assert(aCmp4069.Compute(6) == nts::UNDEFINED);
    assert(aCmp4069.Compute(8) == nts::UNDEFINED);
    assert(aCmp4069.Compute(10) == nts::UNDEFINED);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4069[5] = nts::TRUE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::TRUE);
    assert(aCmp4069.Compute(6) == nts::FALSE);
    assert(aCmp4069.Compute(8) == nts::UNDEFINED);
    assert(aCmp4069.Compute(10) == nts::UNDEFINED);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4069[9] = nts::FALSE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::TRUE);
    assert(aCmp4069.Compute(6) == nts::FALSE);
    assert(aCmp4069.Compute(8) == nts::TRUE);
    assert(aCmp4069.Compute(10) == nts::UNDEFINED);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4069[11] = nts::FALSE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::TRUE);
    assert(aCmp4069.Compute(6) == nts::FALSE);
    assert(aCmp4069.Compute(8) == nts::TRUE);
    assert(aCmp4069.Compute(10) == nts::TRUE);
    assert(aCmp4069.Compute(12) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4069[13] = nts::FALSE;
    assert(aCmp4069.Compute(2) == nts::FALSE);
    assert(aCmp4069.Compute(4) == nts::TRUE);
    assert(aCmp4069.Compute(6) == nts::FALSE);
    assert(aCmp4069.Compute(8) == nts::TRUE);
    assert(aCmp4069.Compute(10) == nts::TRUE);
    assert(aCmp4069.Compute(12) == nts::TRUE);

    std::cout << ".";
    std::cout << "\nSuccess!\n";

    return (0);
}