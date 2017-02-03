//
// Created by duhieu_b on 2/2/17.
//

#include <map>
#include <algorithm>
#include "Parser.hh"

static std::vector<std::string> componentNameVec =
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

}

/*typedef struct s_ast_node
{
    s_ast_node(std::vector<struct s_ast_node *> *children) : children(children) {}
    std::string lexeme;
    ASTNodeType type;
    std::string value;
    std::vector<struct s_ast_node *> *children;
} t_ast_node;*/

void nts::Parser::createNode(std::string &it)
{
    std::map<std::string, nts::FuncPtr>::iterator itm;
    std::vector<std::string>::iterator itv;
    std::string c;
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
    {
        linkName = c.substr(0, c.find(':'));
        linkValue = c.substr(c.find(":") + 1, c.find(' '));
        (this->*myLexMap["link"])();
        linkName = it.replace(it.begin(), it.end(), " ", "").substr(c.length()).substr(0, it.find(':'));
        linkValue = it.replace(it.begin(), it.end(), " ", "").substr(c.length()).substr(it.find(':') + 1);
        (this->*myLexMap["linkEnd"]);
    }
}

nts::t_ast_node *nts::Parser::createTree()
{
    for (std::vector<std::string>::iterator it = lex.begin(); it != lex.end(); it++)
    {
        createNode(*it);
    }
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
