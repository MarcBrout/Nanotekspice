//
// Created by duhieu_b on 2/2/17.
//

#include <map>
#include <algorithm>
#include "Parser.hh"
#include "ComponentFactory.hh"
#include "../component/ComponentFactory.hh"
#include "../component/Components.hh"

static std::array<std::string, 14> componentNameVec =
        {
                "4001",
                "4008",
                "4011",
                "4013",
                "4017",
                "4030",
                "4040",
                "4069",
                "4071",
                "4081",
                "4094",
                "4514",
                "4801",
                "2716",
        };

void nts::Parser::feed(std::string const &input)
{
    lex.push_back(input);
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{
    bool is_chips(false);
    bool is_links(false);
    bool beginLink(false);
    std::array<std::string, 5> nameCompo = {
            "input",
            "output",
            "clock",
            "true",
            "false"
    };
    std::string tmp;
    std::vector<std::string> componentVec;
    size_t pin(0);
    ComponentFactory fact;
    IComponent *first = NULL;

    for (int i = 0; i < root.children->size(); i++)
    {
        tmp = root.children[0][i]->lexeme;
        switch (root.children[0][i]->type)
        {
            case nts::ASTNodeType::SECTION:
                if (tmp == "chipsets")
                {
                    if (!is_chips)
                        is_chips = true;
                    else
                        throw std::logic_error("File corrupted: \"" + tmp + "\" is already used");
                }
                else if (tmp == "links")
                {
                    if (!is_chips)
                        throw std::logic_error("File corrupted: declared " + tmp + "before a chipsets");
                    else
                        is_links = true;
                }
                break;
            case nts::ASTNodeType::COMPONENT:
                if ((std::find(nameCompo.begin(), nameCompo.end(), root.children[0][i]->lexeme) == nameCompo.end() &&
                        std::find(componentNameVec.begin(), componentNameVec.end(), root.children[0][1]->lexeme) == componentNameVec.end()) ||
                        (std::find(nameCompo.begin(), nameCompo.end(), root.children[0][i]->value) != nameCompo.end() ||
                         std::find(componentNameVec.begin(), componentNameVec.end(), root.children[0][i]->value) != componentNameVec.end()))
                {
                    throw std::logic_error("File corrupted: \"" + tmp + "\" is not a valid type component");
                }
                else
                {
                    componentVec.push_back(root.children[0][i]->value);
                    factory.push_back(fact.createComponent(root.children[0][i]->lexeme, root.children[0][i]->value));
                }
                break;
            case nts::ASTNodeType::LINK:
                if (std::find(componentVec.begin(), componentVec.end(), root.children[0][i]->lexeme) == componentVec.end())
                {
                    throw std::logic_error("File corrupted: Component \"" + tmp + "\" doesn't exist.");
                }
                else if (!isdigit(root.children[0][i]->value[0]))
                {
                    throw std::logic_error("File corrupted: Invalid Format, value must be a digit number");
                }
                else if (!is_links)
                {
                    throw std::logic_error("File corrupted: Called a link before the section \"links\"");
                }
                else if (beginLink)
                {
                    throw std::logic_error("File corrupted: Start a new link, but previous link had not finished");
                }
                else
                {
                    beginLink = true;
                    for (std::vector<IComponent *>::iterator it = factory.begin(); it != factory.end() ; ++it)
                    {
                        if (static_cast<nts::AComponent *>(*it)->getName() == tmp)
                        {
                            first = *it;
                            pin = static_cast<size_t>(std::stoi(root.children[0][i]->value));
                            break;
                        }
                    }
                }
                break;
            case nts::ASTNodeType::LINK_END:
                if (std::find(componentVec.begin(), componentVec.end(), root.children[0][i]->lexeme) == componentVec.end())
                {
                    throw std::logic_error("File corrupted: Component \"" + tmp + "\" doesn't exist.");
                }
                else if (!isdigit(root.children[0][i]->value[0]))
                {
                    throw std::logic_error("File corrupted: Invalid Format, value must be a digit number");
                }
                else if (!beginLink)
                {
                    throw std::logic_error("File corrupted: try to end a new link, but no link has been began");
                }
                else
                {
                    beginLink = false;
                    for (std::vector<IComponent *>::iterator it = factory.begin(); it != factory.end() ; ++it)
                    {
                        if (static_cast<nts::AComponent *>(*it)->getName() == tmp)
                        {
                            first->SetLink(pin, **it, static_cast<size_t>(std::stoi(root.children[0][i]->value)));
                            break;
                        }
                    }
                }
                break;
        }
    }
}

void nts::Parser::createNode(std::string &it)
{
    std::map<std::string, nts::FuncPtr>::iterator itm;
    std::array<std::string, 14>::iterator itv;
    std::string c;

    if (myLexMap.empty())
        myLexMap = create_map();
    if (it.find_last_of('#') != 0)
        it = it.substr(0, it.find_last_of('#'));
    c = it[0];
    if (c == ".")
        section(it.substr(1, it.length() - 1));
    else if ((itm = std::find(myLexMap.begin(), myLexMap.end(), c)) != myLexMap.end())
        (this->*itm->second)();
    else if ((itm = std::find(myLexMap.begin(), myLexMap.end(), c = it.substr(0, it.find(' ')))) != myLexMap.end())
        (this->*itm->second)();
    else if ((itv = std::find(componentNameVec.begin(), componentNameVec.end(), c)) != componentNameVec.end())
    {
        nameType = c;
        nameComponent = it.replace(it.begin(), it.end(), " ", "").substr(c.length());
        (this->*myLexMap["name"])();
    }
    else if (c.find(':'))
        linkToNode(it, c);
}

void nts::Parser::linkToNode(std::string &it, const std::string &c)
{
    this->linkName = c.substr(0, c.find(':'));
    this->linkValue = c.substr(c.find(":") + 1, c.find(' '));
    (this->*nts::Parser::myLexMap["link"])();
    this->linkName = it.replace(it.begin(), it.end(), " ", "").substr(c.length()).substr(0, it.find(':'));
    this->linkValue = it.replace(it.begin(), it.end(), " ", "").substr(c.length()).substr(it.find(':') + 1);
    (this->*nts::Parser::myLexMap["linkEnd"]);
}

nts::t_ast_node *nts::Parser::createTree()
{
    for (std::vector<std::string>::iterator it = lex.begin(); it != lex.end(); it++)
        createNode(*it);
    return tree;
}

nts::Parser::Parser()
{
    tree = new nts::t_ast_node;
    tree->lexeme = "";
    tree->type = nts::ASTNodeType::DEFAULT;
    tree->value = "";
}

nts::Parser::~Parser()
{
    if (tree)
        delete tree;
}

void nts::Parser::section(std::string sect)
{
    std::map<std::string, nts::FuncPtr>::iterator it;

    if ((it = std::find(myLexMap.begin(), myLexMap.end(), sect)) == myLexMap.end())
        throw std::logic_error("File corrupted. The section " + sect.substr(0, sect.length() - 1) + " doesn't exist");
    else
        (this->*it->second)();
}

void nts::Parser::chipsets()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::SECTION;
    node->lexeme = "chipsets";
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::links()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::SECTION;
    node->lexeme = "links";
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::newLine()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::NEWLINE;
    node->lexeme = "\n";
    node->value = "";
    tree->children->push_back(node);
}

std::map<std::string, nts::FuncPtr> nts::Parser::create_map()
{
    std::map<std::string, nts::FuncPtr> mymap {
            {"chipsets:", &nts::Parser::chipsets},
            {"links:", &nts::Parser::links},
            {"\n", &nts::Parser::newLine},
            {"input", &nts::Parser::input},
            {"output", &nts::Parser::output},
            {"clock", &nts::Parser::clock},
            {"true", &nts::Parser::trues},
            {"false", &nts::Parser::falses},
            {"name", &nts::Parser::componentName},
            {"#", &nts::Parser::comment},
            {"link", &nts::Parser::link},
            {"linkEnd", &nts::Parser::link_end} };
    return mymap;
}

void nts::Parser::input()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "input";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::output()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "output";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::clock()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "clock";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::trues()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "true";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::falses()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "false";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::componentName()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = nameType;
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::comment()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::STRING;
    node->lexeme = commentString;
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::link()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::LINK;
    node->lexeme = linkName;
    node->value = linkValue;
    tree->children->push_back(node);
}

void nts::Parser::link_end()
{
    t_ast_node *node;

    node = new t_ast_node;
    node->type = nts::ASTNodeType::LINK_END;
    node->lexeme = linkName;
    node->value = linkValue;
    tree->children->push_back(node);
}