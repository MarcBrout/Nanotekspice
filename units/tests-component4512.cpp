//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "Component4512.hh"

int main() {
    nts::Component4512 aCmp4512("TestingComponent4512");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 15; ++i) {
        assert(aCmp4512[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4512.Compute(nts::Component4512::Z) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all Buffer gates";

    aCmp4512[nts::Component4512::A] = nts::TRUE;
    aCmp4512[nts::Component4512::B] = nts::FALSE;
    aCmp4512[nts::Component4512::C] = nts::TRUE;

    aCmp4512[nts::Component4512::X0] = nts::FALSE;
    aCmp4512[nts::Component4512::X1] = nts::FALSE;
    aCmp4512[nts::Component4512::X2] = nts::FALSE;
    aCmp4512[nts::Component4512::X3] = nts::FALSE;
    aCmp4512[nts::Component4512::X4] = nts::FALSE;
    aCmp4512[nts::Component4512::X5] = nts::TRUE;
    aCmp4512[nts::Component4512::X6] = nts::FALSE;
    aCmp4512[nts::Component4512::X7] = nts::FALSE;

    assert(aCmp4512.Compute(nts::Component4512::X5) == nts::TRUE);
    std::cout << ".";

    aCmp4512.resetComputedPins();

    aCmp4512[nts::Component4512::A] = nts::TRUE;
    aCmp4512[nts::Component4512::B] = nts::FALSE;
    aCmp4512[nts::Component4512::C] = nts::FALSE;

    aCmp4512[nts::Component4512::X0] = nts::TRUE;
    aCmp4512[nts::Component4512::X1] = nts::FALSE;
    aCmp4512[nts::Component4512::X2] = nts::TRUE;
    aCmp4512[nts::Component4512::X3] = nts::FALSE;
    aCmp4512[nts::Component4512::X4] = nts::FALSE;
    aCmp4512[nts::Component4512::X5] = nts::TRUE;
    aCmp4512[nts::Component4512::X6] = nts::FALSE;
    aCmp4512[nts::Component4512::X7] = nts::FALSE;

    assert(aCmp4512.Compute(nts::Component4512::Z) == nts::FALSE);
    std::cout << ".";

    aCmp4512.resetComputedPins();

    aCmp4512[nts::Component4512::A] = nts::FALSE;
    aCmp4512[nts::Component4512::B] = nts::TRUE;
    aCmp4512[nts::Component4512::C] = nts::FALSE;

    aCmp4512[nts::Component4512::X0] = nts::TRUE;
    aCmp4512[nts::Component4512::X1] = nts::FALSE;
    aCmp4512[nts::Component4512::X2] = nts::TRUE;
    aCmp4512[nts::Component4512::X3] = nts::FALSE;
    aCmp4512[nts::Component4512::X4] = nts::FALSE;
    aCmp4512[nts::Component4512::X5] = nts::TRUE;
    aCmp4512[nts::Component4512::X6] = nts::FALSE;
    aCmp4512[nts::Component4512::X7] = nts::FALSE;

    aCmp4512[nts::Component4512::INHIB] = nts::TRUE;

    assert(aCmp4512.Compute(nts::Component4512::Z) == nts::FALSE);
    std::cout << ".";

    aCmp4512.resetComputedPins();

    aCmp4512[nts::Component4512::A] = nts::TRUE;
    aCmp4512[nts::Component4512::B] = nts::FALSE;
    aCmp4512[nts::Component4512::C] = nts::FALSE;

    aCmp4512[nts::Component4512::X0] = nts::TRUE;
    aCmp4512[nts::Component4512::X1] = nts::FALSE;
    aCmp4512[nts::Component4512::X2] = nts::TRUE;
    aCmp4512[nts::Component4512::X3] = nts::FALSE;
    aCmp4512[nts::Component4512::X4] = nts::FALSE;
    aCmp4512[nts::Component4512::X5] = nts::TRUE;
    aCmp4512[nts::Component4512::X6] = nts::FALSE;
    aCmp4512[nts::Component4512::X7] = nts::FALSE;

    aCmp4512[nts::Component4512::INHIB] = nts::FALSE;
    aCmp4512[nts::Component4512::OE] = nts::TRUE;

    assert(aCmp4512.Compute(nts::Component4512::Z) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nSuccess!\n";

    return (0);
}