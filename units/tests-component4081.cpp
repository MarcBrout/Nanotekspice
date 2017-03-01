//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4081.hh" 

int main() {
    nts::Component4081 aCmp4081("TestingComponent4081");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4081[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4081.Compute(3) == nts::UNDEFINED);
    assert(aCmp4081.Compute(4) == nts::UNDEFINED);
    assert(aCmp4081.Compute(10) == nts::UNDEFINED);
    assert(aCmp4081.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all and gates";

    aCmp4081[1] = nts::TRUE;
    aCmp4081[2] = nts::TRUE;
    assert(aCmp4081.Compute(3) == nts::TRUE);
    assert(aCmp4081.Compute(4) == nts::UNDEFINED);
    assert(aCmp4081.Compute(10) == nts::UNDEFINED);
    assert(aCmp4081.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4081[5] = nts::FALSE;
    aCmp4081[6] = nts::TRUE;
    assert(aCmp4081.Compute(3) == nts::TRUE);
    assert(aCmp4081.Compute(4) == nts::FALSE);
    assert(aCmp4081.Compute(10) == nts::UNDEFINED);
    assert(aCmp4081.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4081[8] = nts::TRUE;
    aCmp4081[9] = nts::FALSE;
    assert(aCmp4081.Compute(3) == nts::TRUE);
    assert(aCmp4081.Compute(4) == nts::FALSE);
    assert(aCmp4081.Compute(10) == nts::FALSE);
    assert(aCmp4081.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4081[12] = nts::FALSE;
    aCmp4081[13] = nts::FALSE;
    assert(aCmp4081.Compute(3) == nts::TRUE);
    assert(aCmp4081.Compute(4) == nts::FALSE);
    assert(aCmp4081.Compute(10) == nts::FALSE);
    assert(aCmp4081.Compute(11) == nts::FALSE);
    std::cout << ".";
    std::cout << "\nSuccess!\n";

    return (0);
}