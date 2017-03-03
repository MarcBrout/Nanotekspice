//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4071.hh"

int main() {
    nts::Component4071 aCmp4071("TestingComponent4071");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4071[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4071.Compute(3) == nts::UNDEFINED);
    assert(aCmp4071.Compute(4) == nts::UNDEFINED);
    assert(aCmp4071.Compute(10) == nts::UNDEFINED);
    assert(aCmp4071.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all or gates";

    aCmp4071[1] = nts::TRUE;
    aCmp4071[2] = nts::TRUE;
    assert(aCmp4071.Compute(3) == nts::TRUE);
    assert(aCmp4071.Compute(4) == nts::UNDEFINED);
    assert(aCmp4071.Compute(10) == nts::UNDEFINED);
    assert(aCmp4071.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4071[5] = nts::FALSE;
    aCmp4071[6] = nts::TRUE;
    assert(aCmp4071.Compute(3) == nts::TRUE);
    assert(aCmp4071.Compute(4) == nts::TRUE);
    assert(aCmp4071.Compute(10) == nts::UNDEFINED);
    assert(aCmp4071.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4071[8] = nts::TRUE;
    aCmp4071[9] = nts::FALSE;
    assert(aCmp4071.Compute(3) == nts::TRUE);
    assert(aCmp4071.Compute(4) == nts::TRUE);
    assert(aCmp4071.Compute(10) == nts::TRUE);
    assert(aCmp4071.Compute(11) == nts::UNDEFINED);

    std::cout << ".";

    aCmp4071[12] = nts::FALSE;
    aCmp4071[13] = nts::FALSE;
    assert(aCmp4071.Compute(3) == nts::TRUE);
    assert(aCmp4071.Compute(4) == nts::TRUE);
    assert(aCmp4071.Compute(10) == nts::TRUE);
    assert(aCmp4071.Compute(11) == nts::FALSE);
    std::cout << ".";

    std::cout << "\nReseting state of all pins" << std::endl;

    for (size_t i = 1; i <= 13; ++i) {
        aCmp4071[i] = nts::UNDEFINED;
    }

    aCmp4071.SetLink(3, aCmp4071, 2);
    aCmp4071[1] = nts::FALSE;

    assert(aCmp4071.Compute(3) == nts::UNDEFINED);

    aCmp4071[1] = nts::TRUE;

    assert(aCmp4071.Compute(3) == nts::TRUE);

    std::cout << "Success!\n";

    return (0);
}