//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4001.hh"

int main() {
    nts::Component4001 aCmp4001("TestingComponent4001");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4001[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4001.Compute(3) == nts::UNDEFINED);
    assert(aCmp4001.Compute(4) == nts::UNDEFINED);
    assert(aCmp4001.Compute(10) == nts::UNDEFINED);
    assert(aCmp4001.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all nor gates";

    aCmp4001[1] = nts::TRUE;
    aCmp4001[2] = nts::TRUE;
    assert(aCmp4001.Compute(3) == nts::FALSE);
    std::cout << ".";

    aCmp4001[5] = nts::FALSE;
    aCmp4001[6] = nts::TRUE;
    assert(aCmp4001.Compute(4) == nts::FALSE);
    std::cout << ".";

    aCmp4001[8] = nts::TRUE;
    aCmp4001[9] = nts::FALSE;
    assert(aCmp4001.Compute(10) == nts::FALSE);
    std::cout << ".";

    aCmp4001[12] = nts::FALSE;
    aCmp4001[13] = nts::FALSE;
    assert(aCmp4001.Compute(11) == nts::TRUE);
    std::cout << ".";

    aCmp4001[12] = nts::UNDEFINED;
    aCmp4001[13] = nts::FALSE;
    assert(aCmp4001.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    aCmp4001[12] = nts::UNDEFINED;
    aCmp4001[13] = nts::TRUE;
    assert(aCmp4001.Compute(11) == nts::FALSE);
    std::cout << ".";


    std::cout << "\nSuccess!\n";

    return (0);
}