//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentInput.hh"
#include "ComponentOutput.hh"

int main() {
    nts::ComponentInput     aCmpInput("TestingInput");
    nts::ComponentOutput    aCmpOutput("TestingOutput");

    std::cout << "Testing initial state of all pins";

    assert(aCmpOutput.Compute(1) == nts::UNDEFINED);
    std::cout << ".";

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing all output gates";

    aCmpOutput[1] = nts::TRUE;
    assert(aCmpOutput.Compute(1) == nts::TRUE);
    std::cout << ".";

    aCmpOutput[1] = nts::FALSE;
    assert(aCmpOutput.Compute(1) == nts::FALSE);
    std::cout << ".";

    std::cout << "\nLinking an input to the output!\n";
    aCmpOutput[1] = nts::UNDEFINED;
    aCmpInput.SetLink(1, aCmpOutput, 1);
    aCmpInput[1] = nts::TRUE;

    std::cout << "Trying to compute output!\n";
    assert(aCmpOutput.Compute(1) == nts::TRUE);

    std::cout << "Success!\n";

    return (0);
}