//
// Created by duhieu_b on 08/02/17.
//

#include <csignal>
#include <fstream>
#include <algorithm>
#include <ComponentFactory.hh>
#include <Component2716.hh>
#include <cstring>
#include <sstream>
#include "Loop.hh"
#include "Component.hh"

sig_atomic_t signaled = 0;

nts::Loop::Loop()
{
    isLoop = true;
    signaled = 0;
    createCommand();
    createBonus();
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

void nts::Loop::createBonus()
{
    bonus["create"] = &nts::Loop::create;
    bonus["setLink"] = &nts::Loop::setLink;
    bonus["save"] = &nts::Loop::save;
    bonus["destroy"] = &nts::Loop::destroyComponent;
    bonus["destroyLink"] = &nts::Loop::destroyLink;
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
    std::string comm;

    if (commands.find(command) != commands.end())
        (this->*commands[command])();
    else if (bonus.find(command.substr(0, command.find(' '))) != bonus.end())
    {
        if (command.find(' ') != std::string::npos)
        {
            comm = command.substr(command.find(' ') + 1);
            (this->*bonus[command.substr(0, command.find(' '))])(comm);
        }
        else
            std::cout << "Invalid parameter" << std::endl;
    }
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

void nts::Loop::create(std::string &comps)
{
    std::string TypeComp;
    std::string NameComp;
    ComponentFactory fact;

    TypeComp = comps.substr(0, comps.find(' '));
    NameComp = comps.substr(comps.find(' ') + 1);
    if (NameComp.length() == 0)
    {
        std::cerr << "No name component set" << std::endl;
        return;
    }
    if (std::find(nts::ComponentTypeString.begin(), nts::ComponentTypeString.end(), TypeComp) == nts::ComponentTypeString.end())
        std::cerr << "Unknown component" << std::endl;
    else
    {
        if (TypeComp == "2716")
        {
            if (NameComp.find('(') == std::string::npos || NameComp.find(')') == std::string::npos)
                std::cerr << "Name incorrect: \"" + NameComp + "\" is not a valid name 2716 component" << std::endl;
            pars.getFactoryChange().push_back(fact.createComponent(TypeComp, NameComp.substr(0, NameComp.find(')'))));
            if (NameComp.substr(NameComp.find('('), NameComp.find(')')).length() > 2)
                static_cast<Component2716 *>(pars.getFactory().back())->feedRom(NameComp.substr(NameComp.find('('), NameComp.find(')')));
            else
                static_cast<Component2716 *>(pars.getFactory().back())->feedRom("");
        }
        else
            pars.getFactoryChange().push_back(fact.createComponent(TypeComp, NameComp));
    }
}

template<typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

void nts::Loop::setLink(std::string &links)
{
    std::vector<std::string> link;

    split(links, ' ', std::back_inserter(link));
    if (link.size() != 4 || pars.getComponent(link[0]) == nullptr || pars.getComponent(link[2]) == nullptr ||
        std::stoi(link[1]) <= 0 || std::stoi(link[3]) <= 0)
        std::cerr << "Error: setLink nameCompoOne pin nameCompoTwo pin" << std::endl;
    else
    {
        try
        {
            pars.getComponent(link[0])->SetLink(static_cast<size_t >(std::stoi(link[1])),
                                                *(pars.getComponent(link[2])),
                                                static_cast<size_t >(std::stoi(link[3])));
        }
        catch (std::exception& err)
        {
            std::cerr << "Linkage failed: check your link" << std::endl;
        }
    }
}

void nts::Loop::save(std::string &file)
{
    std::ofstream ofs;
    const nts::Link *link;
    nts::AComponent *cmp;
    size_t i;

    ofs.open(file, std::ofstream::trunc);
    if (ofs.is_open())
    {
        ofs << "# File created in the loop\n# Name of the file: ";
        ofs << file << "\n\n.chipsets:\n\n";
        for (std::vector<IComponent *>::const_iterator it = pars.getFactory().begin(); it != pars.getFactory().end(); ++it)
        {
            ofs << nts::ComponentTypeString[static_cast<AComponent *>(*it)->getType()] << "\t\t" << static_cast<AComponent *>(*it)->getName() << "\n";
        }
        ofs << "\n.links:\n";
        for (std::vector<IComponent *>::const_iterator it = pars.getFactory().begin(); it != pars.getFactory().end(); ++it)
        {
            i = 0;
            cmp = static_cast<AComponent *>(*it);
            while ((link = (*cmp)(i++)) != nullptr)
            {
                ofs << static_cast<AComponent *>(*it)->getName() << ":" << link->me << "\t\t" << static_cast<AComponent *>(link->component)->getName() << ":" << link->it << "\n";
            }
        }
    }
}

void nts::Loop::destroyComponent(std::string &destr)
{
    std::vector<IComponent *>::const_iterator it;

    for (it = pars.getFactory().begin(); it != pars.getFactory().end(); it++)
    {
        if (static_cast<AComponent *>(*it)->getName() == destr)
        {
            delete *it;
            break;
        }
    }
    if (it == pars.getFactory().end())
        std::cerr << "Unknown component" << std::endl;
    else
        pars.getFactoryChange().erase(it);
}

void nts::Loop::destroyLink(std::string &destr)
{
    std::vector<std::string> link;

    split(destr, ' ', std::back_inserter(link));
    if (link.size() != 4 || pars.getComponent(link[0]) == nullptr || pars.getComponent(link[2]) == nullptr ||
        std::stoi(link[1]) <= 0 || std::stoi(link[3]) <= 0)
        std::cerr << "Error: destroyLink nameCompoOne pin nameCompoTwo pin" << std::endl;
    static_cast<AComponent *>(pars.getComponent(link[0]))->destroyLink(static_cast<size_t >(std::stoi(link[1])),
                                        pars.getComponent(link[2]),
                                        static_cast<size_t >(std::stoi(link[3])));

}
