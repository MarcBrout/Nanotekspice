//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentInput.hh"
#include "Component4514.hh"

int main() {
    nts::Component4514 aCmp4514("TestingComponent4514");
    nts::ComponentInput aCmpInput("TestingInput");

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 23; ++i) {
        assert(aCmp4514[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4514.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing Decoder gates";

    aCmp4514[1] = nts::TRUE;
    aCmp4514[23] = nts::FALSE;
    aCmp4514[2] = nts::FALSE;
    aCmp4514[3] = nts::FALSE;
    aCmp4514[21] = nts::FALSE;
    aCmp4514[22] = nts::FALSE;

    assert(aCmp4514.Compute(nts::Component4514::S0) == nts::UNDEFINED);

    aCmpInput[1] = nts::TRUE;
    aCmpInput.SetLink(1, aCmp4514, 1);
    aCmp4514.resetComputedPins();

    assert(aCmp4514.Compute(nts::Component4514::S0) == nts::TRUE);
    assert(aCmp4514.Compute(nts::Component4514::S1) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S2) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S3) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S4) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S5) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S6) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S7) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S8) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S9) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S10) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S11) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S12) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S13) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S14) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S15) == nts::FALSE);

    aCmp4514[1] = nts::TRUE;
    aCmp4514[23] = nts::FALSE;
    aCmp4514[2] = nts::TRUE;
    aCmp4514[3] = nts::TRUE;
    aCmp4514[21] = nts::TRUE;
    aCmp4514[22] = nts::FALSE;

    aCmp4514.resetComputedPins();

    assert(aCmp4514.Compute(nts::Component4514::S0) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S1) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S2) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S3) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S4) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S5) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S6) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S7) == nts::TRUE);
    assert(aCmp4514.Compute(nts::Component4514::S8) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S9) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S10) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S11) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S12) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S13) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S14) == nts::FALSE);
    assert(aCmp4514.Compute(nts::Component4514::S15) == nts::FALSE);

    std::cout << ".";
    std::cout << "\nSuccess!\n";

    return (0);
}