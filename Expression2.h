#include <string>


#ifndef HEADERFILE_H
#define HEADERFILE_H

class Expression
{
    public:

        Expression(std::string e);
        Expression();
        std::string to_string();
        double evaluate();
    
    private:

        std::string expression{};
        // Node* a{};
        //Node* lhs{};
        //Node* rhs{};


};

#endif