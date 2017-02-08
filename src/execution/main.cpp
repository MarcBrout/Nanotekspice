//
// Created by duhieu_b on 06/02/17.
//

#include <iostream>
#include "Parser.hh"
#include "Loop.hh"

int main(int argc, char **argv)
{
    nts::Loop loop;
    try
    {
        if (!loop.run(argc, argv))
            return 1;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}