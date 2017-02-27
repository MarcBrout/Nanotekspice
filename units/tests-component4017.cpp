//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include <iostream>
#include "ComponentClock.hh"
#include "Component4017.hh"

int main() {
    nts::Component4017 aCmp4017("TestingComponent4017");
    nts::ComponentClock cp0("CP0");
    nts::ComponentClock cp1("CP1");

    std::cout << "Testing initial state of all Pins";

    assert(aCmp4017[nts::Component4017::Q0] == nts::TRUE);
    assert(aCmp4017[nts::Component4017::Q1] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q2] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q3] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q4] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q5] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q6] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q7] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q8] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q9] == nts::FALSE);
    assert(aCmp4017[nts::Component4017::Q59] == nts::TRUE);

    std::cout << "\nAll pins correctly initialized!\n";
    std::cout << "Testing Johnson decade counter";

    cp0[1] = nts::TRUE;
    cp1[1] = nts::FALSE;
    cp0.SetLink(1, aCmp4017, 14);
    cp1.SetLink(1, aCmp4017, 13);

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::FALSE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();

    assert(aCmp4017.Compute(nts::Component4017::Q0) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q1) == nts::TRUE);
    assert(aCmp4017.Compute(nts::Component4017::Q2) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q3) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q4) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q5) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q6) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q7) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q8) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q9) == nts::FALSE);
    assert(aCmp4017.Compute(nts::Component4017::Q59) == nts::TRUE);

    cp0.resetComputedPins();
    cp1.resetComputedPins();
    aCmp4017.resetComputedPins();
    std::cout << ".";
    std::cout << "\nSuccess!\n";
    return (0);
}