#include <string>
#include "token.h"

#ifndef HEADERFILE_H
#define HEADERFILE_H

class Expression
{
    public:

        Expression(std::string e);
        Expression();
        std::string to_prefix();
        std::string to_postfix();
        std::string to_infix();


        double evaluate();
    
    private:

        std::string expression{};
        // Node* a{};
        //Node* lhs{};
        //Node* rhs{};


};

#endif