//
// Created by brout_m on 06/02/17.
//

#ifndef CPP_NANOTEKSPICE_COMPONENT4801_HH
#define CPP_NANOTEKSPICE_COMPONENT4801_HH


#include <fstream>
#include "Component.hh"

namespace nts
{
    class Component4801 : public AComponent
    {
    public:
        enum PINS {
            A7 = 1,
            A6 = 2,
            A5 = 3,
            A4 = 4,
            A3 = 5,
            A2 = 6,
            A1 = 7,
            A0 = 8,
            DQ0 = 9,
            DQ1 = 10,
            DQ2 = 11,
            DQ3 = 13,
            DQ4 = 14,
            DQ5 = 15,
            DQ6 = 16,
            DQ7 = 17,
            CE = 18,
            NC = 19,
            OE = 20,
            WE = 21,
            A9 = 22,
            A8 = 23
        };

        ~Component4801();
        Component4801(std::string const& name);
        virtual nts::Tristate Compute(size_t pin_num_this = 1);

    private:
        Component4801() = delete;
        Component4801(Component4801 const& cmp) = delete;
        Component4801 &operator=(Component4801 const& cmp) = delete;
        std::vector<char> ram;
    };
}


#endif //CPP_NANOTEKSPICE_COMPONENT4801_HH
