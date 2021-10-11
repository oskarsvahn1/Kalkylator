#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "Expression2.h"
#include "Operators.h"
#include "postfix.h"
#include "token.h"
#include <stack>

using namespace std;

// stack<Node*> node_stack;

Expression::Expression(string e):
    expression{e}
{   
    //stack<Node*> node_stack;
    //node_stack.pop();
    Postfix* postfix_string = new Postfix{e}; 
    string postfx{postfix_string->to_string()};
    istringstream iss{postfx};
    Token word{};

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
        else if (word.is_operator())
        {
            if(node_stack.size() < 2)
            {
                throw logic_error("No guilty operator2.");
            }

            Node* rhs = node_stack.top();
            node_stack.pop();
            Node* lhs = node_stack.top();
            node_stack.pop();

            if (word == "+")
            {
                Node* a = new Addition{lhs, rhs};
                node_stack.push(a);
            }
            else if (word == "-")
            {
                Node* a = new Subtraction{lhs, rhs};
                node_stack.push(a);
            }            
            else if (word == "*")
            {
                Node* a = new Multiplication{lhs, rhs};
                node_stack.push(a);
            }            
            else if (word == "/")
            {
                Node* a = new Division{lhs, rhs};
                node_stack.push(a);
            }
            else if (word == "^")
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
        
        throw logic_error("Stack size must be one in the end.");

    } 
}

Expression::Expression():
    expression{"0"}
{
    Node* a = new Addition{new Integer{10}, new Integer{4}};
    node_stack.push(a);
}

double Expression::evaluate()
{

    return node_stack.top()->evaluate();
}
string Expression::to_prefix()
{
    return node_stack.top()->prefix();
}
string Expression::to_postfix()
{
    return node_stack.top()->postfix();
}
string Expression::to_infix()
{
    return node_stack.top()->infix();
}


// Node* Expression::clone()
// {
//     // expression{"0"};
//     Node* a{};// = new (Node{""});
//     a = node_stack.top()->clone();
//     // new Expression{a};
//     // node_stack.push(a);
//     return a;
// }