//
// Created by brout_m on 08/02/17.
//

#include <cassert>
#include "ComponentFactory.hh"
#include "Component4001.hh"

int main() {
    nts::ComponentFactory   factory;
    nts::IComponent         *iCmp4001 = factory.createComponent("4001", "TestingComponent4001");
    nts::AComponent         &aCmp4001 = static_cast<nts::AComponent &>(*iCmp4001);


    for (size_t i = 1; i <= 13; ++i)
        assert(aCmp4001[i]== nts::UNDEFINED);

    assert(aCmp4001.Compute(3) == nts::UNDEFINED);
    assert(aCmp4001.Compute(4) == nts::UNDEFINED);
    assert(aCmp4001.Compute(10) == nts::UNDEFINED);
    assert(aCmp4001.Compute(11) == nts::UNDEFINED);

    aCmp4001[1] = nts::TRUE;
    aCmp4001[2] = nts::TRUE;
    assert(aCmp4001.Compute(3) == nts::FALSE);

    aCmp4001[5] = nts::FALSE;
    aCmp4001[6] = nts::TRUE;
    assert(aCmp4001.Compute(4) == nts::FALSE);

    aCmp4001[8] = nts::TRUE;
    aCmp4001[9] = nts::FALSE;
    assert(aCmp4001.Compute(10) == nts::FALSE);

    aCmp4001[12] = nts::FALSE;
    aCmp4001[13] = nts::FALSE;
    assert(aCmp4001.Compute(11) == nts::TRUE);

    return (0);
}