#include <string>
#include "token.h"
#include <stack>
#include "Operators.h"

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
        // Node* clone();



        double evaluate();
    
    private:

        std::string expression{};
        std::stack<Node*> node_stack;

        // Node* a{};
        //Node* lhs{};
        //Node* rhs{};

};

#endif