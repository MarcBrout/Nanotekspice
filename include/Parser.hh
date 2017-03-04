//
// Created by duhieu_b on 2/2/17.
//

#ifndef CPP_NANOTEKSPICE_PARSER_HH
#define CPP_NANOTEKSPICE_PARSER_HH


#include <iostream>
#include <vector>
#include <map>
#include "IParser.hh"
#include "IComponent.hh"

namespace nts
{
    class Parser;
    typedef void (nts::Parser::*FuncPtr)(void);

    class Parser : public nts::IParser
    {
    private:
        nts::t_ast_node *tree;
        std::vector<std::string> lex;
        std::vector<nts::IComponent *> factory;
        std::vector<nts::IComponent *> outputVec;
        std::vector<nts::IComponent *> inputVec;
        std::string nameComponent;
        std::string nameType;
        std::string linkName;
        std::string linkValue;
        std::string commentString;

        std::map<std::string, nts::FuncPtr> create_map();
        Parser(Parser const& pars) = delete;
        Parser &operator=(Parser const& pars) = delete;
        void createNode(std::string it);

        // Section
        void section(std::string sect, std::map<std::string, nts::FuncPtr> &myLexMap);
        void chipsets();
        void links();

        // '\n'
        void newLine();

        //components

        void input();
        void output();
        void clock();
        void trues();
        void falses();
        void componentName();

        // Links
        void linkToNode(std::string &it, const std::string &c, std::map<std::string, nts::FuncPtr> &myLexMap);
        void link();
        void link_end();

        // Comments
        void comment();

    public:
        Parser();
        virtual ~Parser();
        void sortComponent();
        void feed(std::string const &input);
        void parseTree(nts::t_ast_node &root);
        nts::t_ast_node &getRoot();
        const std::vector<IComponent *> &getOutputVec() const;
        const std::vector<IComponent *> &getInputVec() const;
        const std::vector<IComponent *> &getFactory() const;
        std::vector<IComponent *> &getFactoryChange();
        IComponent *getComponent(std::string const& name) const;
        nts::t_ast_node *createTree();
    };
}

#endif //CPP_NANOTEKSPICE_PARSER_HH
