#include "Operators.h"

#include <sstream>

#include <iomanip>

#include <cmath>

#include <iostream>

#include <string>

using namespace std;

//11 : 50 rader
// 16 :10 rader




Operator::Operator(Node* const & lhs, Node* const & rhs):
    Node{}, opl{lhs}, opr{rhs}
{
}

string Operator::postfix() 
{
    return opl->postfix() + " " + opr->postfix() + " " + token();
}

string Operator::infix() 
{
    return "( " + opl->infix() + " " + token()  + " " + opr->infix() + " )";
}

string Operator::prefix()
{
    return string(1, token()) + " " + opl->prefix() + " " + opr->prefix();
}

double Addition::evaluate()
{
    return opl->evaluate() + opr->evaluate();
}

Addition::Addition(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

char Addition::token()
{
    return '+';
}

Subtraction::Subtraction(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

double Subtraction::evaluate()
{
    return opl->evaluate() - opr->evaluate();
} 

char Subtraction::token() 
{
    return '-';
}


Multiplication::Multiplication(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

double Multiplication::evaluate()
{
    return opl->evaluate() * opr->evaluate();
} 

char Multiplication::token() 
{
    return '*';
}


Division::Division(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

double Division::evaluate()
{
    if(opr->evaluate() == 0)
    {
        throw std::logic_error("Divide by zero.");
    }
    return opl->evaluate() / opr->evaluate();
} 

char Division::token() 
{
    return '/';
}



Exponentiation::Exponentiation(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

double Exponentiation::evaluate()
{
    if (opl->evaluate() == 0 && opr->evaluate() < 0)
    {
        throw std::logic_error("Zero to negative exponent.");
    }
    
    if (opl->evaluate() < 0 && fmod(opr->evaluate(), 1) != 0)
    {
        throw std::logic_error("Negative number to nonint exponent.");
    }
    
    return pow(opl->evaluate(),  opr->evaluate());
} 

char Exponentiation::token() 
{
    return '^';
}



Operand::Operand():
    Node{}
{
}

Integer::Integer(int i):
    Operand{}, x{i}
{
}

Real::Real(float r):
    Operand{}, x{r}
{
}

string Integer::postfix()
{
    return to_string(x);
}

string Real::postfix()
{
    ostringstream oss{};
    oss << fixed << setprecision(3) << x;
    return oss.str();
}

string Variable::postfix()
{
    return x;
}


string Integer::infix()
{
    return to_string(x);
}

string Real::infix()
{
    ostringstream oss{};
    oss << fixed << setprecision(3) << x;
    return oss.str();
}

string Variable::infix()
{
    return x;
}



string Integer::prefix()
{
    return to_string(x);
}

string Real::prefix()
{
    ostringstream oss{};
    oss << fixed << setprecision(3) << x;
    return oss.str();
}

string Variable::prefix()
{
    return x;
}


Variable::Variable(string x):
    Operand{}, x{x}
{
}

double Real::evaluate()
{
    double value = (int)(x * 1000 + .5);  // Round to 3 decimal places.
    return (double)value / 1000;

}

double Integer::evaluate()
{
    return this-> x;
}

double Variable::evaluate()
{
    return 0;
}

