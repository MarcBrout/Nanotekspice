//
// Created by duhieu_b on 08/02/17.
//

#include <csignal>
#include <Component.hh>
#include <fstream>
#include "Loop.hh"

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

    ifs.open(file, std::basic_ios::in);
    if (ifs.is_open())
    {
        while (std::getline(ifs, str, '\n').good())
            pars.feed(str);
        pars.createTree();
        pars.parseTree(pars.getRoot());
    }
    else
    {
        throw std::logic_error("Error: " + file + " : This file doesn't exist");
    }
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
    for (std::vector<IComponent *>::const_iterator it = pars.getOutputVec().begin(); it != pars.getOutputVec().end() ; ++it)
    {
        std::cout << static_cast<AComponent *>(*it)->getName() << "=" << static_cast<int>(static_cast<AComponent *>(*it)[0][1]) << std::endl;
    }
}

void nts::Loop::Simulate()
{
    for (std::vector<IComponent *>::const_iterator it = pars.getOutputVec().begin(); it != pars.getOutputVec().end() ; ++it)
    {
        static_cast<AComponent *>(*it)->Compute();
    }
}

void nts::Loop::LoopSimulate()
{
    void (nts::Loop::*prev_handler)(int);
    static_cast<__sighandler_t>(prev_handler) = signal(SIGINT, my_handler);
    while (!signaled)
    {
        for (std::vector<IComponent *>::const_iterator it = pars.getOutputVec().begin(); it != pars.getOutputVec().end() ; ++it)
        {
            static_cast<AComponent *>(*it)->Compute();
        }
    }
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
            if (!static_cast<AComponent *>(*it)->setPin(static_cast<AComponent *>(*it)[0][1], static_cast<nts::Tristate>(pin)))
                std::cout << "Error: Pin isn't valid" << std::endl;
            break;
        }
    }
    if (it == pars.getInputVec().end())
    {
        std::cout << "Error: Cannot set pin: Component name doesn't exist" << std::endl;
    }
}

void nts::Loop::my_handler(int signal)
{
    signaled = 1;
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
    launchCommand("Simulate");
    launchCommand("Display");
    std::cout << "> ";
    while (isLoop)
    {
        std::getline(std::cin, command);
        if (!std::cin.eof())
        {
            std::cout << "Quit" << std::endl;
            break;
        }
        else
        {
            launchCommand(command);
            std::cout << "> " << std::endl;
        }
    }
    return true:
}
