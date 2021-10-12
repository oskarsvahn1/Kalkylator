#include "Operators.h"

#include <sstream>

#include <iomanip>

#include <cmath>

#include <iostream>

#include <string>
#include <memory>

using namespace std;

//11 : 50 rader
// 16 :10 rader

<<<<<<< Updated upstream
=======
Node(Node const& rhs)
{
    std::unique_ptr<Node> a = (&rhs)->clone();
}


Node& Node::operator=(Node const rhs)
{
    std::unique_ptr<Node> a = (&rhs)->clone();
}

Node::Move(Node const rhs)
{
   std::unique_ptr<Node> a = (&rhs);
}
>>>>>>> Stashed changes

Node& Node::operator=(Node const rhs)
{
    std::unique_ptr<Node> a = (&rhs);
}

<<<<<<< Updated upstream
=======
Operator::Operator(unique_ptr<Node> const & lhs, unique_ptr<Node> const & rhs):
    Node{}, opl{std::make_unique<Node>(lhs)}, opr{std::make_unique<Node>(rhs)}
{
}
// Operator::~Operator()
// {
//     // delete[] a;
//     // delete[] a;
// }


std::unique_ptr<Node> Operator::clone() 
{
     return this->construct(opl->clone(), opr->clone());
}

>>>>>>> Stashed changes



<<<<<<< Updated upstream
Operator::Operator(Node* const & lhs, Node* const & rhs):
    Node{}, opl{lhs}, opr{rhs}
{
}

=======
>>>>>>> Stashed changes
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
    // return 0;
    return opl->evaluate() + opr->evaluate();
}

double abs(double const a)
{
    return fabs(a);
}

<<<<<<< Updated upstream
Addition::Addition(Node* const & lhs, Node* const & rhs):
=======

Addition::Addition(std::unique_ptr<Node> const & lhs, unique_ptr<Node> const & rhs):
>>>>>>> Stashed changes
    Operator{lhs, rhs}
{
}

char Addition::token()
{
    return '+';
}

<<<<<<< Updated upstream
Subtraction::Subtraction(Node* const & lhs, Node* const & rhs):
=======
std::unique_ptr<Node> Addition::construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs)
{
    return std::make_unique<Addition>(lhs, rhs);
 
}


Subtraction::Subtraction(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs):
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
=======
std::unique_ptr<Node> Subtraction::construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs)
{
    return std::make_unique<Subtraction>(lhs, rhs);
}
>>>>>>> Stashed changes

Multiplication::Multiplication(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs):
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

<<<<<<< Updated upstream
=======
std::unique_ptr<Node> Multiplication::construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs)
{
    return std::make_unique<Multiplication>(lhs, rhs);
}
>>>>>>> Stashed changes

Division::Division(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs):
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

<<<<<<< Updated upstream

=======
std::unique_ptr<Node> Division::construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs)
{
    return std::make_unique<Division>(lhs, rhs);
}
>>>>>>> Stashed changes

Exponentiation::Exponentiation(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs):
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

<<<<<<< Updated upstream
=======
std::unique_ptr<Node> Exponentiation::construct(std::unique_ptr<Node> const & lhs, std::unique_ptr<Node> const & rhs)
{
    return std::make_unique<Exponentiation>(lhs, rhs);
}
>>>>>>> Stashed changes


Operand::Operand():
    Node{}
{
}

<<<<<<< Updated upstream
=======

// Operand::~Operand()
// {
//     // delete x;
// }



>>>>>>> Stashed changes
Integer::Integer(int i):
    Operand{}, x{i}
{
}

Real::Real(float r):
    Operand{}, x{r}
{
}

<<<<<<< Updated upstream
=======
std::unique_ptr<Node> Integer::clone()
{
    return std::make_unique<Integer>(x);
}

std::unique_ptr<Node> Real::clone() 
{
    return std::make_unique<Real>(x);
}

>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
=======
std::unique_ptr<Node> Variable::clone() 
{
    return std::make_unique<Variable>(x);
}

>>>>>>> Stashed changes
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

