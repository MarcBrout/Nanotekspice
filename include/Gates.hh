//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_GATES_HH
#define CPP_NANOTEKSPICE_GATES_HH

#include "IComponent.hh"

namespace nts
{
    class Gates
    {
    public:
        ~Gates(){};

        static nts::Tristate nand(nts::Tristate in1, nts::Tristate in2);
        static nts::Tristate nor(nts::Tristate in1, nts::Tristate in2);
        static nts::Tristate _xor(nts::Tristate in1, nts::Tristate in2);
        static nts::Tristate _and(nts::Tristate in1, nts::Tristate in2);
        static nts::Tristate _or(nts::Tristate in1, nts::Tristate in2);
        static nts::Tristate add(nts::Tristate in1, nts::Tristate in2, nts::Tristate cin, nts::Tristate& cout);
        static nts::Tristate flipflop(nts::Tristate clock, nts::Tristate reset, nts::Tristate data, nts::Tristate set, nts::Tristate& q, nts::Tristate& nq, bool which);
        static nts::Tristate inverter(nts::Tristate in1);
        static nts::Tristate _and(nts::Tristate in1, nts::Tristate in2, nts::Tristate in3, nts::Tristate in4);
    };
}

#endif //CPP_NANOTEKSPICE_GATES_HH
