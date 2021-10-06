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
        int* a{};
        int* lhs{};
        int* rhs{};


};

#endif