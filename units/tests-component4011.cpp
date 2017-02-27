//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4011.hh"

int main() {
    nts::Component4011 aCmp4011("Testing4011");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4011[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4011.Compute(3) == nts::UNDEFINED);
    assert(aCmp4011.Compute(4) == nts::UNDEFINED);
    assert(aCmp4011.Compute(10) == nts::UNDEFINED);
    assert(aCmp4011.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all nand gates";

    aCmp4011[1] = nts::TRUE;
    aCmp4011[2] = nts::TRUE;
    assert(aCmp4011.Compute(3) == nts::FALSE);
    std::cout << ".";

    aCmp4011[5] = nts::FALSE;
    aCmp4011[6] = nts::TRUE;
    assert(aCmp4011.Compute(4) == nts::TRUE);
    std::cout << ".";

    aCmp4011[8] = nts::TRUE;
    aCmp4011[9] = nts::FALSE;
    assert(aCmp4011.Compute(10) == nts::TRUE);
    std::cout << ".";

    aCmp4011[12] = nts::FALSE;
    aCmp4011[13] = nts::FALSE;
    assert(aCmp4011.Compute(11) == nts::TRUE);
    std::cout << ".";
    std::cout << "\nSuccess!\n";

    return (0);
}