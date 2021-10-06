#ifndef HEADERFILE_H
#define HEADERFILE_H

class Expression
{
    public:

        Expression(std::string e);
        to_string();
        evaluate();
    
    private:

        std::string expression;
};

#endif