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
// Operator::~Operator()
// {
//     delete[] opl;
//     delete opr;
// }




// Node* Operator::clone() 
// {
//     return this->construct(opl->clone(), opr->clone());
// }


// Expression* Operand::clone() const
// {
//     Expression* e = new Integer{name};
//     return e;
// }


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

double abs(double const a)
{
    return fabs(a);
}


Addition::Addition(Node* const & lhs, Node* const & rhs):
    Operator{lhs, rhs}
{
}

char Addition::token()
{
    return '+';
}

Node* Addition::construct(Node* const & lhs, Node* const & rhs)
{
    return new Addition(lhs, rhs);
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

Node* Subtraction::construct(Node* const & lhs, Node* const & rhs)
{
    return new Subtraction(lhs, rhs);
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

Node* Multiplication::construct(Node* const & lhs, Node* const & rhs)
{
    return new Multiplication(lhs, rhs);
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

Node* Division::construct(Node* const & lhs, Node* const & rhs)
{
    return new Division(lhs, rhs);
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

Node* Exponentiation::construct(Node* const & lhs, Node* const & rhs)
{
    return new Exponentiation(lhs, rhs);
}


Operand::Operand():
    Node{}
{
}

// Operand::~Operand()
// {
// }


Integer::Integer(int i):
    Operand{}, x{i}
{
}

Real::Real(float r):
    Operand{}, x{r}
{
}

// Node* Integer::clone()
// {
//     return new Integer{x};
// }

// Node* Real::clone() 
// {
//     return new Real{x};
// }

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

// Node* Variable::clone() 
// {
//     Node* e = new Variable{x};
//     return e;
// }

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

