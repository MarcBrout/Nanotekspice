//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentInput.hh"

int main() {
    nts::ComponentInput aCmpInput("TestingInput");

    std::cout << "Testing initial state of all pins";

    assert(aCmpInput.Compute(1) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all input gates";

    aCmpInput[1] = nts::TRUE;
    assert(aCmpInput.Compute(1) == nts::TRUE);
    std::cout << ".";

    aCmpInput[1] = nts::FALSE;
    assert(aCmpInput.Compute(1) == nts::FALSE);
    std::cout << ".";

    std::cout << "\nSuccess!\n";

    return (0);
}