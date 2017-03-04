//
// Created by duhieu_b on 08/02/17.
//

#include <csignal>
#include <fstream>
#include <algorithm>
#include "Loop.hh"
#include "Component.hh"

sig_atomic_t signaled = 0;

nts::Loop::Loop()
{
    isLoop = true;
    signaled = 0;
    createCommand();
}

nts::Loop::~Loop()
{
}

void nts::Loop::launchPars(std::string const& file)
{
    std::fstream ifs;
    std::string str;

    ifs.open(file, std::fstream::in);
    if (ifs.is_open())
    {
        while (std::getline(ifs, str, '\n').good())
            pars.feed(str);
        pars.feed(str);
        pars.createTree();
        pars.parseTree(pars.getRoot());
    }
    else
    {
        ifs.close();
        throw std::logic_error("Error: " + file + " : This file doesn't exist");
    }
    ifs.close();
}

void nts::Loop::createCommand()
{
    commands["exit"] = &nts::Loop::Exit;
    commands["display"] = &nts::Loop::Display;
    commands["simulate"] = &nts::Loop::Simulate;
    commands["loop"] = &nts::Loop::LoopSimulate;
    commands["dump"] = &nts::Loop::Dump;
}

void nts::Loop::Exit()
{
    isLoop = false;
}

void nts::Loop::Display()
{
    int i;

    for (std::vector<IComponent *>::const_iterator it = pars.getOutputVec().begin(); it != pars.getOutputVec().end() ; ++it)
    {
        std::cout << static_cast<AComponent *>(*it)->getName() << "=";
        i = static_cast<int>(static_cast<AComponent *>(*it)[0][1]);
        if (i >= 0)
            std::cout << i << std::endl;
        else
            std::cout << "U" << std::endl;
    }
}

void nts::Loop::Simulate()
{
    for (std::vector<IComponent *>::const_iterator it = pars.getOutputVec().begin(); it != pars.getOutputVec().end() ; ++it)
    {
        static_cast<AComponent *>(*it)->Compute();
    }
    for (std::vector<IComponent *>::const_iterator it = pars.getFactory().begin(); it != pars.getFactory().end() ; ++it)
    {
        static_cast<AComponent *>(*it)->resetComputedPins();
    }

}

void    my_handler(int sig)
{
    if (sig == SIGINT)
        signaled = 1;
}

void nts::Loop::LoopSimulate()
{
    signal(SIGINT, my_handler);
    while (!signaled)
    {
        Simulate();
    }
    signaled = 0;
}

void nts::Loop::Dump()
{
    for (std::vector<IComponent *>::const_iterator it = pars.getFactory().begin(); it != pars.getFactory().end() ; ++it)
    {
        static_cast<AComponent *>(*it)->Dump();
    }
}

void nts::Loop::setPin(std::string &name, int pin)
{
    std::vector<IComponent *>::const_iterator it;
    for (it = pars.getInputVec().begin(); it != pars.getInputVec().end() ; ++it)
    {
        if (static_cast<AComponent *>(*it)->getName() == name)
        {
            if (pin < -1 || pin > 1)
                std::cout << "Error: Pin value isn't valid" << std::endl;
            else if (!static_cast<AComponent *>(*it)->setPin(1, static_cast<nts::Tristate>(pin)))
                std::cout << "Error: Pin isn't valid" << std::endl;
            break;
        }
    }
    if (it == pars.getInputVec().end())
    {
        std::cout << "Error: Cannot set pin: Component name doesn't exist" << std::endl;
    }
}

void nts::Loop::launchCommand(std::string const &command)
{
    std::string comp;
    std::string pin;

    if (commands.find(command) != commands.end())
        (this->*commands[command])();
    else if (command.find('=') != std::string::npos && std::isdigit(command[command.find('=') + 1]))
    {
        comp = command.substr(0, command.find('='));
        pin = command.substr(command.find('=') + 1);
        setPin(comp, std::stoi(pin));
    }
    else
        std::cout << "Unknown component" << std::endl;
}

bool nts::Loop::run(int argc, char **argv)
{
    int i;
    std::string command;

    if (argc < 2)
    {
        std::cout << "Error: Usage: ./nanotekspice fileName [nameComponent=Pin] ..." << std::endl;
        return false;
    }
    launchPars(argv[1]);
    i = 2;
    while (i < argc)
    {
        launchCommand(argv[i]);
        i++;
    }
    launchCommand("simulate");
    pars.sortComponent();
    launchCommand("display");
    std::cout << "> ";
    while (isLoop)
    {
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            break;
        }
        else
        {
            launchCommand(command);
            if (isLoop)
                std::cout << "> ";
        }
    }
    return true;
}