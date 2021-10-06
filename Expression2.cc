#include <sstream>
#include <iostream>

#include <cctype>
#include <algorithm>
#include "Expression2.h"
#include "Operators2.h"
#include <stack>

using namespace std;



Expression::Expression(string e):
    expression{e}
{
    string word{};
    istringsteam iss{expression};
    stack<Node*> stack;

    while(iss >> word)
    {

        if ( std::all_of( begin(word), end(word), ::isdigit ) )
        {
        // Vi har hittat ett heltal
            Node* a = new Integer{(int) word};
            stack.push(a);

        }
        else if ( isdigit(word.at(0)) )
        {
        // Vi räknar ordet som flyttal
            Node* a = new Real{(float) word};
            stack.push(a);
        }
        else if ( isalpha(word.at(0)) )
        {
        // Vi räknar ordet som variabelnamn
            Node* a = new Variable{word};
            stack.push(a);
        }
        else if (word.find_first_of('+-*/^') != std::string::npos)
        {
            if(stack.size < 2)
            {
                throw std::logic_error;
            
            }

            rhs = stack.top();
            lhs = stack.top();
            stack.pop();
            stack.pop();
            
            if (word == "+")
            {
                Node* a = new Addition{lhs, rhs};
            }
            if (word == "-")
            {
                Node* a = new Subtraction{lhs, rhs};
            }            
            if (word == "*")
            {
                Node* a = new Multiplication{lhs, rhs};
            }            
            if (word == "/")
            {
                Node* a = new Division{lhs, rhs};
            }
            if (word == "^")
            {
                Node* a = new Exponentiation{lhs, rhs};
            } 
            else
            {
                throw std::logic_error;
            }
            stack.push(a);
        }

    }   
    
    if (stack.size != 1)
    {
        throw std::logic_error;

    } 


    // bool is_operator(std::string word)
    // {
    //     return word.find_first_of('+-*/^') != std::string::npos;
            
    // }

    // bool is_operand(std::string word)
    // {
    //     return word.find_first_of('12334567890') != std::string::npos;
            
    // }

}

Expression::Expression():
    expression{"0"}
{
}

double Expression::evaluate()
{
    return 0;
}