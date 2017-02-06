//
// Created by duhieu_b on 2/2/17.
//

#ifndef CPP_NANOTEKSPICE_PARSER_HH
#define CPP_NANOTEKSPICE_PARSER_HH


#include <iostream>
#include <vector>
#include "IParser.hh"
#include "IComponent.hh"

namespace nts
{
    typedef void (nts::Parser::*FuncPtr)(void);

    class Parser : public nts::IParser
    {
    private:
        nts::t_ast_node *tree;
        std::vector<std::string> lex;
        std::vector<nts::IComponent *> factory;
        std::string nameComponent;
        std::string nameType;
        std::string linkName;
        std::string linkValue;
        std::string commentString;
       // static std::map<std::string, nts::FuncPtr> myLexMap;

        std::map<std::string, nts::FuncPtr> create_map();
    protected:
        void createNode(std::string &it);

        void section(std::string sect);
        void chipsets();
        void links();

        void newLine();

        //components

        void input();
        void output();
        void clock();
        void trues();
        void falses();
        void componentName();

        void linkToNode(std::string &it, const std::string &c);

        void link();

        void link_end();

        void comment();

    public:
        Parser();

        virtual ~Parser();

        void show_tree();

        void feed(std::string const &input) override;

        void parseTree(nts::t_ast_node &root) override;

        nts::t_ast_node &getRoot();
        nts::t_ast_node *createTree() override;
    };
}

#endif //CPP_NANOTEKSPICE_PARSER_HH
