#include <string>
#include "token.h"
<<<<<<< Updated upstream
=======
#include <stack>
#include "Operators.h"
#include <memory>
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
=======
        // std::stack<Node*> node_stack;
        std::stack<std::unique_ptr<Node>> node_stack;

        // std::unique_ptr<Expression*> expresssion;

>>>>>>> Stashed changes
        // Node* a{};
        //Node* lhs{};
        //Node* rhs{};


};

#endif