//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include <list>
#include <algorithm>
#include "ComponentInput.hh"
#include "ComponentClock.hh"
#include "Component4094.hh"

void resetComponents(std::list<nts::AComponent*>& components)
{
    std::for_each(components.begin(), components.end(), [](nts::AComponent *cmp) { cmp->resetComputedPins(); });
}

int main() {
    nts::Component4094 aCmp4094("TestingComponent4094");
    nts::ComponentInput input("input");
    nts::ComponentInput strobe("strobe");
    nts::ComponentInput out("out");
    nts::ComponentClock cp0("CP0");

    std::list<nts::AComponent*> components = {
            &aCmp4094,
            &input,
            &strobe,
            &out,
            &cp0
    };

    std::cout << "Testing initial state of all Pins";

    assert(aCmp4094[nts::Component4094::Q1] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q2] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q3] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q4] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q5] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q6] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q7] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::Q8] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::QS] == nts::UNDEFINED);
    assert(aCmp4094[nts::Component4094::NQS] == nts::UNDEFINED);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing 8-BIT Shift Register";

    resetComponents(components);

    out[1] = nts::TRUE;
    cp0[1] = nts::TRUE;
    input[1] = nts::TRUE;
    strobe[1] = nts::TRUE;

    out.SetLink(1, aCmp4094, nts::Component4094::OUT);
    cp0.SetLink(1, aCmp4094, nts::Component4094::CP0);
    input.SetLink(1, aCmp4094, nts::Component4094::DATA);
    strobe.SetLink(1, aCmp4094, nts::Component4094::STROBE);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::UNDEFINED);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::UNDEFINED);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    input[1] = nts::FALSE;

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS) == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS) == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS) == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    input[1] = nts::TRUE;

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    std::cout << "\nOutput Disabled Tests";

    out[1] = nts::FALSE;

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::UNDEFINED);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);
    out[1] = nts::TRUE;

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::FALSE);
    std::cout << ".";

    resetComponents(components);

    assert(aCmp4094.Compute(nts::Component4094::Q1) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q2) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q3) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q4) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q5) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::Q6) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q7) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::Q8) == nts::FALSE);
    assert(aCmp4094.Compute(nts::Component4094::QS) == nts::TRUE);
    assert(aCmp4094.Compute(nts::Component4094::NQS)  == nts::TRUE);
    std::cout << ".";

    resetComponents(components);
    std::cout << "\nSuccess!\n";
    return (0);
}