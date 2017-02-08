//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentFactory.hh"
#include "Component4030.hh"

int main() {
    nts::ComponentFactory   factory;
    nts::IComponent         *iCmp4030 = factory.createComponent("4030", "TestingComponent4030");
    nts::AComponent         &aCmp4030 = static_cast<nts::AComponent &>(*iCmp4030);

    std::cout << "Testing initial state of all pins";

    for (size_t i = 1; i <= 13; ++i) {
        assert(aCmp4030[i] == nts::UNDEFINED);
        std::cout << ".";
    }

    assert(aCmp4030.Compute(3) == nts::UNDEFINED);
    assert(aCmp4030.Compute(4) == nts::UNDEFINED);
    assert(aCmp4030.Compute(10) == nts::UNDEFINED);
    assert(aCmp4030.Compute(11) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all xor gates";

    aCmp4030[1] = nts::TRUE;
    aCmp4030[2] = nts::TRUE;
    assert(aCmp4030.Compute(3) == nts::FALSE);
    std::cout << ".";

    aCmp4030[5] = nts::FALSE;
    aCmp4030[6] = nts::TRUE;
    assert(aCmp4030.Compute(4) == nts::TRUE);
    std::cout << ".";

    aCmp4030[8] = nts::TRUE;
    aCmp4030[9] = nts::FALSE;
    assert(aCmp4030.Compute(10) == nts::TRUE);
    std::cout << ".";

    aCmp4030[12] = nts::FALSE;
    aCmp4030[13] = nts::FALSE;
    assert(aCmp4030.Compute(11) == nts::FALSE);
    std::cout << ".";
    std::cout << "\nSuccess!\n";

    return (0);
}