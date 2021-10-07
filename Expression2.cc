#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "Expression2.h"
#include "Operators.h"
#include <stack>

using namespace std;


//Move to H-file when possible.
stack<Node*> node_stack;





Expression::Expression(string e):
    expression{e}
{
    string word{};
    istringstream iss{expression};

    while(iss >> word)
    {

        if ( std::all_of( begin(word), end(word), ::isdigit ) )
        {
        // Vi har hittat ett heltal
            Node* a = new Integer{stoi(word)};
            node_stack.push(a);
        }
        else if ( isdigit(word.at(0)) )
        {
        // Vi räknar ordet som flyttal
            Node* a = new Real{stof(word)};
            node_stack.push(a);
        }
        else if ( isalpha(word.at(0)) )
        {
        // Vi räknar ordet som variabelnamn
            Node* a = new Variable{word};
            node_stack.push(a);
        }
        else if (word.find_first_of("+-*/^") != std::string::npos)
        {
            if(node_stack.size() < 2)
            {
                throw logic_error("No guilty operator.");
            
            }

            Node* rhs = node_stack.top();
            Node* lhs = node_stack.top();
            node_stack.pop();
            node_stack.pop();
            
            if (word == "+")
            {
                Node* a = new Addition{lhs, rhs};
                node_stack.push(a);
            }
            if (word == "-")
            {
                Node* a = new Subtraction{lhs, rhs};
                node_stack.push(a);
            }            
            if (word == "*")
            {
                Node* a = new Multiplication{lhs, rhs};
                node_stack.push(a);
            }            
            if (word == "/")
            {
                Node* a = new Division{lhs, rhs};
                node_stack.push(a);
            }
            if (word == "^")
            {
                Node* a = new Exponentiation{lhs, rhs};
                node_stack.push(a);
            } 
            else
            {
                throw logic_error("No guilty operator.");
            }
        }

    }   
    
    if (node_stack.size() != 1)
    {
        throw logic_error("Stack size not one in the end.");

    } 

}

Expression::Expression():
    expression{"0"}
{
    Node* a = new Integer{0};
    node_stack.push(a);
}

double Expression::evaluate()
{
    return node_stack.top()->evaluate();
}