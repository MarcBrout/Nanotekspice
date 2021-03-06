//
// Created by duhieu_b on 2/2/17.
//

#include <map>
#include <algorithm>
#include <Component2716.hh>
#include "Parser.hh"
#include "ComponentFactory.hh"
#include "Component.hh"

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
    IComponent *first = nullptr;

    for (size_t i = 0; i < root.children->size(); i++)
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
                if (std::find(nameCompo.begin(), nameCompo.end(), root.children[0][i]->lexeme) == nameCompo.end() &&
                    std::find(componentNameVec.begin(), componentNameVec.end(), root.children[0][i]->lexeme) == componentNameVec.end())
                {
                    throw std::logic_error("File corrupted: \"" + tmp + "\" is not a valid type component");
                }

                if (root.children[0][i]->lexeme == "2716")
                {
                    if (root.children[0][i]->value.find('(') == std::string::npos || root.children[0][i]->value.find(')') == std::string::npos)
                        throw std::logic_error("File corrupted: \"" + tmp + "\" is not a valid type component");
                    componentVec.push_back(root.children[0][i]->value.substr(0, root.children[0][i]->value.find('(')));
                    factory.push_back(fact.createComponent(root.children[0][i]->lexeme, root.children[0][i]->value.substr(0, root.children[0][i]->value.find('('))));
                    if (root.children[0][i]->value.substr(root.children[0][i]->value.find('('), root.children[0][i]->value.find(')')).length() > 2)
                        static_cast<Component2716 *>(factory.back())->feedRom(root.children[0][i]->value.substr(root.children[0][i]->value.find('('), root.children[0][i]->value.find(')')));
                    else
                        static_cast<Component2716 *>(factory.back())->feedRom("");
                }
                else
                {
                    componentVec.push_back(root.children[0][i]->value);
                    factory.push_back(fact.createComponent(root.children[0][i]->lexeme, root.children[0][i]->value));
                }
                if (root.children[0][i]->lexeme == "output")
                {
                    first = factory.back();
                    outputVec.push_back(first);
                    first = nullptr;
                }
                else if (root.children[0][i]->lexeme == "input" || root.children[0][i]->lexeme == "clock")
                {
                    first = factory.back();
                    inputVec.push_back(first);
                    first = nullptr;
                }
                break;
            case nts::ASTNodeType::LINK:
                if (std::find(componentVec.begin(), componentVec.end(), tmp) == componentVec.end())
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
                if (std::find(componentVec.begin(), componentVec.end(), tmp) == componentVec.end())
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
            default:
                break;
        }
    }
}

std::map<std::string, nts::FuncPtr> nts::Parser::create_map()
{
    std::map<std::string, nts::FuncPtr> mymap;

    mymap["chipsets:"] = &nts::Parser::chipsets;
    mymap["links:"] = &nts::Parser::links;
    mymap["\n"] = &nts::Parser::newLine;
    mymap["input"] = &nts::Parser::input;
    mymap["output"] = &nts::Parser::output;
    mymap["clock"] = &nts::Parser::clock;
    mymap["true"] = &nts::Parser::trues;
    mymap["false"] = &nts::Parser::falses;
    mymap["name"] = &nts::Parser::componentName;
    mymap["#"] = &nts::Parser::comment;
    mymap["link"] = &nts::Parser::link;
    mymap["linkEnd"] = &nts::Parser::link_end;
    return mymap;
}

void nts::Parser::createNode(std::string it)
{
    std::map<std::string, nts::FuncPtr> myLexMap;
    std::map<std::string, nts::FuncPtr>::iterator itm;
    std::string c;
    size_t pos;

    if ((pos = (it.find_first_not_of(' '))) == std::string::npos)
        pos = 0;
    it = it.substr(pos);
    if (myLexMap.empty())
        myLexMap = create_map();
    if (it.find_last_of('#') != 0)
        it = it.substr(0, it.find_last_of('#'));
    c = it[0];
    if (c == ".")
    {
        section(it.substr(1, it.length() - 1), myLexMap);
        return;
    }
    if ((itm = myLexMap.find(c)) != myLexMap.end())
    {
        (this->*itm->second)();
        return ;
    }
    if (it.find(' ') < it.find('\t'))
        c = it.substr(0, it.find(' '));
    else
        c = it.substr(0, it.find('\t'));
    if ((itm = myLexMap.find(c)) != myLexMap.end())
    {
        it.erase(std::remove(it.begin(), it.end(), ' '), it.end());
        it.erase(std::remove(it.begin(), it.end(), '\t'), it.end());
        nameComponent = it.substr(c.length());
        (this->*itm->second)();
    }
    else if (std::find(componentNameVec.begin(), componentNameVec.end(), c) != componentNameVec.end())
    {
        nameType = c;
        it.erase(std::remove(it.begin(), it.end(), ' '), it.end());
        it.erase(std::remove(it.begin(), it.end(), '\t'), it.end());
        nameComponent = it.substr(c.length());
        (this->*myLexMap["name"])();
    }
    else if (c.find(':') != std::string::npos)
        linkToNode(it, c, myLexMap);
}

void nts::Parser::linkToNode(std::string &it, const std::string &c, std::map<std::string, nts::FuncPtr> &myLexMap)
{
    this->linkName = c.substr(0, c.find(':'));
    this->linkValue = c.substr(c.find(":") + 1, c.find(' '));
    (this->*myLexMap["link"])();
    it.erase(std::remove(it.begin(), it.end(), ' '), it.end());
    it.erase(std::remove(it.begin(), it.end(), '\t'), it.end());
    it = it.substr(c.length());
    this->linkName = it.substr(0, it.find(':'));
    this->linkValue = it.substr(it.find(':') + 1);
    (this->*myLexMap["linkEnd"])();
}

nts::t_ast_node *nts::Parser::createTree()
{
    for (std::vector<std::string>::iterator it = lex.begin(); it != lex.end(); it++)
        createNode(*it);
    return tree;
}

nts::Parser::Parser()
{
    std::vector<struct s_ast_node *> *vec = new std::vector<struct s_ast_node *>();
    tree = new t_ast_node(vec);
    tree->lexeme = "";
    tree->type = nts::ASTNodeType::DEFAULT;
    tree->value = "";
}

nts::Parser::~Parser()
{
    for (std::vector<struct s_ast_node*>::iterator it = tree->children->begin(); it != tree->children->end(); ++it)
        delete *it;
    for (std::vector<IComponent *>::iterator it = factory.begin(); it != factory.end(); ++it)
        delete *it;
    delete tree->children;
    delete tree;
}

void nts::Parser::section(std::string sect, std::map<std::string, nts::FuncPtr> &myLexMap)
{
    std::map<std::string, nts::FuncPtr>::iterator it;

    if ((it = myLexMap.find(sect)) == myLexMap.end())
        throw std::logic_error("File corrupted. The section " + sect.substr(0, sect.length() - 1) + " doesn't exist");
    else
        (this->*it->second)();
}

void nts::Parser::chipsets()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::SECTION;
    node->lexeme = "chipsets";
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::links()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::SECTION;
    node->lexeme = "links";
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::newLine()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::NEWLINE;
    node->lexeme = "\n";
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::input()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "input";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::output()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "output";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::clock()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "clock";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::trues()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "true";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::falses()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = "false";
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::componentName()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::COMPONENT;
    node->lexeme = nameType;
    node->value = nameComponent;
    tree->children->push_back(node);
}

void nts::Parser::comment()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::STRING;
    node->lexeme = commentString;
    node->value = "";
    tree->children->push_back(node);
}

void nts::Parser::link()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::LINK;
    node->lexeme = linkName;
    node->value = linkValue;
    tree->children->push_back(node);
}

void nts::Parser::link_end()
{
    t_ast_node *node;

    node = new t_ast_node(tree->children);
    node->type = nts::ASTNodeType::LINK_END;
    node->lexeme = linkName;
    node->value = linkValue;
    tree->children->push_back(node);
}

nts::t_ast_node &nts::Parser::getRoot()
{
    return *tree;
}

const std::vector<nts::IComponent *> &nts::Parser::getOutputVec() const
{
    return outputVec;
}

const std::vector<nts::IComponent *> &nts::Parser::getInputVec() const
{
    return inputVec;
}

const std::vector<nts::IComponent *> &nts::Parser::getFactory() const
{
    return factory;
}

static bool sortFunction(const nts::IComponent * a, const nts::IComponent * b)
{
    std::string const &first = static_cast<nts::AComponent const *>(a)->getName();
    std::string const &second = static_cast<nts::AComponent const *>(b)->getName();

    return first.compare(second) < 0;
}

void nts::Parser::sortComponent()
{
    std::sort(outputVec.begin(), outputVec.end(), sortFunction);
}

std::vector<nts::IComponent *> &nts::Parser::getFactoryChange()
{
    return factory;
}

nts::IComponent *nts::Parser::getComponent(std::string const &name) const
{
    for (std::vector<nts::IComponent *>::const_iterator it = factory.begin(); it != factory.end(); ++it)
    {
        if (static_cast<AComponent *>(*it)->getName() == name)
            return *it;
    }
    return nullptr;
}
