//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include "ComponentFactory.hh"
#include "Component4008.hh"

int main() {
    nts::ComponentFactory   factory;
    nts::IComponent         *iCmp4008 = factory.createComponent("4008", "TestingComponent4008");
    nts::AComponent         &aCmp4008 = static_cast<nts::AComponent &>(*iCmp4008);


    for (size_t i = 1; i <= 15; ++i)
        assert(aCmp4008[i] == nts::UNDEFINED);

    assert(aCmp4008.Compute(10) == nts::UNDEFINED);
    assert(aCmp4008.Compute(11) == nts::UNDEFINED);
    assert(aCmp4008.Compute(12) == nts::UNDEFINED);
    assert(aCmp4008.Compute(13) == nts::UNDEFINED);
    assert(aCmp4008.Compute(14) == nts::UNDEFINED);

    aCmp4008[6] = nts::TRUE;
    aCmp4008[7] = nts::TRUE;
    aCmp4008[9] = nts::TRUE;
    assert(aCmp4008.Compute(10) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::TRUE);

    aCmp4008[4] = nts::FALSE;
    aCmp4008[5] = nts::TRUE;
    assert(aCmp4008.Compute(11) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);

    aCmp4008[2] = nts::TRUE;
    aCmp4008[3] = nts::FALSE;
    assert(aCmp4008.Compute(12) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);

    aCmp4008[15] = nts::FALSE;
    aCmp4008[1] = nts::FALSE;
    assert(aCmp4008.Compute(13) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);

    aCmp4008[6] = nts::FALSE;
    aCmp4008[7] = nts::FALSE;
    aCmp4008[9] = nts::FALSE;
    assert(aCmp4008.Compute(10) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::FALSE);

    aCmp4008[4] = nts::FALSE;
    aCmp4008[5] = nts::TRUE;
    assert(aCmp4008.Compute(11) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);

    aCmp4008[2] = nts::TRUE;
    aCmp4008[3] = nts::FALSE;
    assert(aCmp4008.Compute(12) == nts::TRUE);
    assert(aCmp4008.Compute(14) == nts::FALSE);

    aCmp4008[15] = nts::TRUE;
    aCmp4008[1] = nts::TRUE;
    assert(aCmp4008.Compute(13) == nts::FALSE);
    assert(aCmp4008.Compute(14) == nts::TRUE);
    return (0);
}