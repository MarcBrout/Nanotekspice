//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include <list>
#include <algorithm>
#include "ComponentInput.hh"
#include "ComponentOutput.hh"
#include "Component2716.hh"

void resetComponents(std::list<nts::AComponent*>& components)
{
    std::for_each(components.begin(), components.end(), [](nts::AComponent *cmp) { cmp->resetComputedPins(); });
}

int main() {
    nts::Component2716 aCmp2716("TestingComponent2716");
    nts::ComponentOutput dq0("dq0");
    nts::ComponentOutput dq1("dq1");
    nts::ComponentOutput dq2("dq2");
    nts::ComponentOutput dq3("dq3");
    nts::ComponentOutput dq4("dq4");
    nts::ComponentOutput dq5("dq5");
    nts::ComponentOutput dq6("dq6");
    nts::ComponentOutput dq7("dq7");
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
    nts::ComponentInput a10("a10");
    nts::ComponentInput g("g");
    nts::ComponentInput pgm("prm");

    std::list<nts::AComponent*> components = {
            &aCmp2716,
            &dq0,
            &dq1,
            &dq2,
            &dq3,
            &dq4,
            &dq5,
            &dq6,
            &dq7,
            &g,
            &pgm,
            &a0,
            &a1,
            &a2,
            &a3,
            &a4,
            &a5,
            &a6,
            &a7,
            &a8,
            &a9,
            &a10
    };

    std::cout << "Testing initial state of all Pins";

    assert(aCmp2716[nts::Component2716::Q0] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q1] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q2] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q3] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q4] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q5] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q6] == nts::UNDEFINED);
    assert(aCmp2716[nts::Component2716::Q7] == nts::UNDEFINED);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing ROM";

    aCmp2716.feedRom("rom.bin");

    g[1] = nts::TRUE;
    pgm[1] = nts::TRUE;

    a0[1] = nts::TRUE;
    a1[1] = nts::FALSE;
    a2[1] = nts::FALSE;
    a3[1] = nts::FALSE;

    a4[1] = nts::TRUE;
    a5[1] = nts::FALSE;
    a6[1] = nts::FALSE;
    a7[1] = nts::FALSE;
    a8[1] = nts::FALSE;
    a9[1] = nts::FALSE;
    a10[1] = nts::FALSE;

    dq0.SetLink(1, aCmp2716, nts::Component2716::Q0);
    dq1.SetLink(1, aCmp2716, nts::Component2716::Q1);
    dq2.SetLink(1, aCmp2716, nts::Component2716::Q2);
    dq3.SetLink(1, aCmp2716, nts::Component2716::Q3);
    dq4.SetLink(1, aCmp2716, nts::Component2716::Q4);
    dq5.SetLink(1, aCmp2716, nts::Component2716::Q5);
    dq6.SetLink(1, aCmp2716, nts::Component2716::Q6);
    dq7.SetLink(1, aCmp2716, nts::Component2716::Q7);

    g.SetLink(1, aCmp2716, nts::Component2716::G);
    pgm.SetLink(1, aCmp2716, nts::Component2716::PGM);

    a0.SetLink(1, aCmp2716, nts::Component2716::A0);
    a1.SetLink(1, aCmp2716, nts::Component2716::A1);
    a2.SetLink(1, aCmp2716, nts::Component2716::A2);
    a3.SetLink(1, aCmp2716, nts::Component2716::A3);

    a4.SetLink(1, aCmp2716, nts::Component2716::A4);
    a5.SetLink(1, aCmp2716, nts::Component2716::A5);
    a6.SetLink(1, aCmp2716, nts::Component2716::A6);
    a7.SetLink(1, aCmp2716, nts::Component2716::A7);
    a8.SetLink(1, aCmp2716, nts::Component2716::A8);
    a9.SetLink(1, aCmp2716, nts::Component2716::A9);
    a10.SetLink(1, aCmp2716, nts::Component2716::A10);

    assert(aCmp2716.Compute(nts::Component2716::Q0) == nts::TRUE);
    assert(aCmp2716.Compute(nts::Component2716::Q1) == nts::FALSE);
    assert(aCmp2716.Compute(nts::Component2716::Q2) == nts::FALSE);
    assert(aCmp2716.Compute(nts::Component2716::Q3) == nts::FALSE);
    assert(aCmp2716.Compute(nts::Component2716::Q4) == nts::FALSE);
    assert(aCmp2716.Compute(nts::Component2716::Q5) == nts::FALSE);
    assert(aCmp2716.Compute(nts::Component2716::Q6) == nts::TRUE);
    assert(aCmp2716.Compute(nts::Component2716::Q7) == nts::FALSE);

    std::cout << ".";

    resetComponents(components);

    std::cout << "\nSuccess!\n";
    return (0);
}