//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentClock.hh"
#include "Component4013.hh"

int main() {
    nts::Component4013 aCmp4013("Testing4013");
    nts::ComponentClock aCmpClock1("TestingClock");


    std::cout << "Testing initial state of all Pins";

    aCmpClock1[1] = nts::TRUE;

    for (size_t i = 1; i <= 13; ++i) {
        std::cout << ".";
        assert(aCmp4013[i] == nts::UNDEFINED);
    }

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing internal flipflop gates";

    aCmpClock1.SetLink(1, aCmp4013, 3);

    aCmp4013[4] = nts::FALSE;
    aCmp4013[5] = nts::TRUE;
    aCmp4013[6] = nts::FALSE;
    assert(aCmp4013.Compute(1) == nts::TRUE);
    assert(aCmp4013.Compute(2) == nts::FALSE);
    aCmp4013.resetComputedPins();
    aCmpClock1.resetComputedPins();
    assert(aCmp4013.Compute(1) == nts::TRUE);
    assert(aCmp4013.Compute(2) == nts::FALSE);
    assert(aCmpClock1[1] == nts::FALSE);
    aCmp4013.resetComputedPins();
    aCmpClock1.resetComputedPins();
    assert(aCmp4013.Compute(1) == nts::TRUE);
    assert(aCmp4013.Compute(2) == nts::FALSE);
    assert(aCmpClock1[1] == nts::TRUE);
    aCmp4013.resetComputedPins();
    aCmpClock1.resetComputedPins();
    assert(aCmp4013.Compute(1) == nts::TRUE);
    assert(aCmp4013.Compute(2) == nts::FALSE);
    assert(aCmpClock1[1] == nts::FALSE);
    aCmp4013.resetComputedPins();
    aCmpClock1.resetComputedPins();

    aCmp4013[4] = nts::TRUE;
    assert(aCmp4013.Compute(1) == nts::FALSE);
    assert(aCmp4013.Compute(2) == nts::TRUE);
    assert(aCmpClock1[1] == nts::TRUE);
    aCmp4013.resetComputedPins();
    aCmpClock1.resetComputedPins();
    aCmp4013[4] = nts::FALSE;
    assert(aCmp4013.Compute(1) == nts::FALSE);
    assert(aCmp4013.Compute(2) == nts::TRUE);
    assert(aCmpClock1[1] == nts::FALSE);


    std::cout << ".";

    std::cout << "\nSuccess!\n";
    return (0);
}