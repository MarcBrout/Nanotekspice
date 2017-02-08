//
// Created by duhieu_b on 08/02/17.
//

#ifndef CPP_NANOTEKSPICE_LOOP_HH
#define CPP_NANOTEKSPICE_LOOP_HH

#include "Parser.hh"

namespace nts
{
    class Loop;

    typedef void (nts::Loop::*ComPtr)(void);
    class Loop
    {
    private:
        nts::Parser pars;
        std::map<std::string, ComPtr> commands;
        bool isLoop;
        int signaled;
        //typedef void (nts::Loop::*handler)(int);

        Loop(Loop const &loop) = delete;

        Loop &operator=(Loop const &loop) = delete;

        void createCommand();

        void my_handler(int signal);
        void Exit();
        void Display();
        void Simulate();
        void LoopSimulate();
        void Dump();

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
