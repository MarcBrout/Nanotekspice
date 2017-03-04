//
// Created by duhieu_b on 08/02/17.
//

#ifndef CPP_NANOTEKSPICE_LOOP_HH
#define CPP_NANOTEKSPICE_LOOP_HH

#include "Parser.hh"
#include "Component.hh"

namespace nts
{
    class Loop;

    typedef void (nts::Loop::*ComPtr)(void);
    typedef void (nts::Loop::*BonPtr)(std::string &);

    class Loop
    {
    private:
        nts::Parser pars;
        std::map<std::string, ComPtr> commands;
        std::map<std::string, BonPtr> bonus;
        bool isLoop;

        Loop(Loop const &loop) = delete;

        Loop &operator=(Loop const &loop) = delete;

        void createCommand();
        void createBonus();

        void Exit();
        void Display();
        void Simulate();
        void LoopSimulate();
        void Dump();

        void create(std::string &comps);
        void setLink(std::string &links);
        void save(std::string &file);
        void destroyComponent(std::string &destr);
        void destroyLink(std::string &destr);

        void launchPars(std::string const& file);
        void setPin(std::string &name, int pin);
        void launchCommand(std::string const& command);
    public:
        Loop();

        virtual ~Loop();

        bool run(int argc, char **argv);
    };
}

#endif //CPP_NANOTEKSPICE_LOOP_HH
