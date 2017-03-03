//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include <list>
#include <algorithm>
#include "ComponentInput.hh"
#include "Component4801.hh"

void resetComponents(std::list<nts::AComponent*>& components)
{
    std::for_each(components.begin(), components.end(), [](nts::AComponent *cmp) { cmp->resetComputedPins(); });
}

int main() {
    nts::Component4801 aCmp4801("TestingComponent4801");
    nts::ComponentInput dq0("dq0");
    nts::ComponentInput dq1("dq1");
    nts::ComponentInput dq2("dq2");
    nts::ComponentInput dq3("dq3");
    nts::ComponentInput dq4("dq4");
    nts::ComponentInput dq5("dq5");
    nts::ComponentInput dq6("dq6");
    nts::ComponentInput dq7("dq7");
    nts::ComponentInput a0("a0");
    nts::ComponentInput a1("a1");
    nts::ComponentInput a2("a2");
    nts::ComponentInput a3("a3");
    nts::ComponentInput a4("a4");
    nts::ComponentInput a5("a5");
    nts::ComponentInput a6("a6");
    nts::ComponentInput a7("a7");
    nts::ComponentInput a8("a8");
    nts::ComponentInput a9("a9");
    nts::ComponentInput we("we");
    nts::ComponentInput oe("oe");
    nts::ComponentInput ce("ce");

    std::list<nts::AComponent*> components = {
            &aCmp4801,
            &dq0,
            &dq1,
            &dq2,
            &dq3,
            &dq4,
            &dq5,
            &dq6,
            &dq7,
            &we,
            &oe,
            &ce,
            &a0,
            &a1,
            &a2,
            &a3,
            &a4,
            &a5,
            &a6,
            &a7,
            &a8,
            &a9
    };

    std::cout << "Testing initial state of all Pins";

    assert(aCmp4801[nts::Component4801::DQ0] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ1] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ2] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ3] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ4] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ5] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ6] == nts::UNDEFINED);
    assert(aCmp4801[nts::Component4801::DQ7] == nts::UNDEFINED);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing RAM";

    resetComponents(components);

    dq0[1] = nts::TRUE;
    dq1[1] = nts::FALSE;
    dq2[1] = nts::FALSE;
    dq3[1] = nts::FALSE;
    dq4[1] = nts::FALSE;
    dq5[1] = nts::FALSE;
    dq6[1] = nts::TRUE;
    dq7[1] = nts::FALSE;

    ce[1] = nts::TRUE;
    we[1] = nts::TRUE;
    oe[1] = nts::TRUE;

    a1[1] = nts::FALSE;
    a6[1] = nts::TRUE;
    a8[1] = nts::TRUE;

    a0[1] = nts::TRUE;
    a2[1] = nts::FALSE;
    a3[1] = nts::FALSE;
    a4[1] = nts::FALSE;
    a5[1] = nts::FALSE;
    a7[1] = nts::FALSE;
    a9[1] = nts::FALSE;

    dq0.SetLink(1, aCmp4801, nts::Component4801::DQ0);
    dq1.SetLink(1, aCmp4801, nts::Component4801::DQ1);
    dq2.SetLink(1, aCmp4801, nts::Component4801::DQ2);
    dq3.SetLink(1, aCmp4801, nts::Component4801::DQ3);
    dq4.SetLink(1, aCmp4801, nts::Component4801::DQ4);
    dq5.SetLink(1, aCmp4801, nts::Component4801::DQ5);
    dq6.SetLink(1, aCmp4801, nts::Component4801::DQ6);
    dq7.SetLink(1, aCmp4801, nts::Component4801::DQ7);

    ce.SetLink(1, aCmp4801, nts::Component4801::CE);
    oe.SetLink(1, aCmp4801, nts::Component4801::OE);
    we.SetLink(1, aCmp4801, nts::Component4801::WE);

    a1.SetLink(1, aCmp4801, nts::Component4801::A1);
    a6.SetLink(1, aCmp4801, nts::Component4801::A6);
    a8.SetLink(1, aCmp4801, nts::Component4801::A8);

    a0.SetLink(1, aCmp4801, nts::Component4801::A0);
    a2.SetLink(1, aCmp4801, nts::Component4801::A2);
    a3.SetLink(1, aCmp4801, nts::Component4801::A3);
    a4.SetLink(1, aCmp4801, nts::Component4801::A4);
    a5.SetLink(1, aCmp4801, nts::Component4801::A5);
    a7.SetLink(1, aCmp4801, nts::Component4801::A7);
    a9.SetLink(1, aCmp4801, nts::Component4801::A9);

    assert(aCmp4801.Compute(nts::Component4801::DQ0) == nts::TRUE);
    assert(aCmp4801.Compute(nts::Component4801::DQ1) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ2) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ3) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ4) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ5) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ6) == nts::TRUE);
    assert(aCmp4801.Compute(nts::Component4801::DQ7) == nts::FALSE);

    std::cout << ".";

    resetComponents(components);

    we[1] = nts::FALSE;

    assert(aCmp4801.Compute(nts::Component4801::DQ0) == nts::TRUE); 
    assert(aCmp4801.Compute(nts::Component4801::DQ1) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ2) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ3) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ4) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ5) == nts::FALSE);
    assert(aCmp4801.Compute(nts::Component4801::DQ6) == nts::TRUE);
    assert(aCmp4801.Compute(nts::Component4801::DQ7) == nts::FALSE);

    std::cout << "\nSuccess!\n";
    return (0);
}