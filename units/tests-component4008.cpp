//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4008.hh"

int main() {
    nts::Component4008 aCmp4008("TestingComponent4008");

    std::cout << "Testing initial state of all Pins";

    for (size_t i = 1; i <= 15; ++i) {
        std::cout << ".";
        assert(aCmp4008[i] == nts::UNDEFINED);
    }


    assert(aCmp4008.Compute(10) == nts::UNDEFINED);
    assert(aCmp4008.Compute(11) == nts::UNDEFINED);
    assert(aCmp4008.Compute(12) == nts::UNDEFINED);
    assert(aCmp4008.Compute(13) == nts::UNDEFINED);
    assert(aCmp4008.Compute(14) == nts::UNDEFINED);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing internal adding gates";

    aCmp4008[6] = nts::TRUE;
    aCmp4008[7] = nts::TRUE;
    aCmp4008[9] = nts::TRUE;
    assert(aCmp4008.Compute(10) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::TRUE);
    std::cout << ".";

    aCmp4008[4] = nts::FALSE;
    aCmp4008[5] = nts::TRUE;
    assert(aCmp4008.Compute(11) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);
    std::cout << ".";

    aCmp4008[2] = nts::TRUE;
    aCmp4008[3] = nts::FALSE;
    assert(aCmp4008.Compute(12) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);
    std::cout << ".";

    aCmp4008[15] = nts::FALSE;
    aCmp4008[1] = nts::FALSE;
    assert(aCmp4008.Compute(13) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);
    std::cout << ".";

    aCmp4008[6] = nts::FALSE;
    aCmp4008[7] = nts::FALSE;
    aCmp4008[9] = nts::FALSE;
    assert(aCmp4008.Compute(10) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::FALSE);
    std::cout << ".";

    aCmp4008[4] = nts::FALSE;
    aCmp4008[5] = nts::TRUE;
    assert(aCmp4008.Compute(11) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);
    std::cout << ".";

    aCmp4008[2] = nts::TRUE;
    aCmp4008[3] = nts::FALSE;
    assert(aCmp4008.Compute(12) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);
    std::cout << ".";

    aCmp4008[15] = nts::TRUE;
    aCmp4008[1] = nts::TRUE;
    assert(aCmp4008.Compute(13) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);
    std::cout << ".";

    std::cout << "\nAll gates working!";
    std::cout << "\nTesting Computing of last Pin";

    for (size_t i = 1; i <= 15; ++i) {
        std::cout << ".";
        assert(aCmp4008[i] = nts::UNDEFINED);
    }

    aCmp4008[6] = nts::TRUE;
    aCmp4008[7] = nts::FALSE;
    aCmp4008[9] = nts::TRUE;
    aCmp4008[4] = nts::FALSE;
    aCmp4008[5] = nts::FALSE;
    aCmp4008[2] = nts::FALSE;
    aCmp4008[3] = nts::TRUE;
    aCmp4008[15] = nts::TRUE;
    aCmp4008[1] = nts::TRUE;
    std::cout << ".";

    aCmp4008.resetComputedPins();
    assert(aCmp4008.Compute(13) == nts::FALSE);
    std::cout << ".";
    assert(aCmp4008.Compute(14) == nts::TRUE);
    std::cout << ".";
    assert(aCmp4008[12] == nts::TRUE);
    assert(aCmp4008[11] == nts::TRUE);
    assert(aCmp4008[10] == nts::FALSE);
    std::cout << ".";
    std::cout << "\nSuccess!\n";
    return (0);
}