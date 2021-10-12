#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "Expression2.h"
#include "Operators.h"
#include "postfix.h"
#include "token.h"
#include <stack>
#include <memory>

using namespace std;

<<<<<<< Updated upstream

//Move to H-file when possible.
stack<Node*> node_stack;
=======
// stack<std::unique_ptr<Node>> node_stack;
>>>>>>> Stashed changes

Expression::Expression(string e):
    expression{e}
{   
<<<<<<< Updated upstream
    node_stack.pop();
    Postfix* postfix_string = new Postfix{e}; 
=======
    //stack<std::unique_ptr<Node>> node_stack;
    //node_stack.pop();
    // Postfix* postfix_string = new Postfix{e}; 
    unique_ptr<Postfix> postfix_string(new Postfix{e});

>>>>>>> Stashed changes
    string postfx{postfix_string->to_string()};
    istringstream iss{postfx};
    Token word{};

    while(iss >> word)
    {
        if ( std::all_of( begin(word), end(word), ::isdigit ) )
        {
        // Vi har hittat ett heltal
            // unique_ptr<Integer> a(new Integer{stoi(word)});
            unique_ptr<Integer> a = std::make_unique<Integer>(stoi(word));


            // std::unique_ptr<Node> a = new Integer{stoi(word)};
            node_stack.push(std::move(a));
        }
        else if ( isdigit(word.at(0)) )
        {
        // Vi räknar ordet som flyttal
            // unique_ptr<Real> a(new Real{stof(word)});
            unique_ptr<Real> a = std::make_unique<Real>(stof(word));


            // std::unique_ptr<Node> a = new Real{stof(word)};
            node_stack.push(std::move(a));
        }
        else if ( isalpha(word.at(0)) )
        {
        // Vi räknar ordet som variabelnamn
            // unique_ptr<Variable> a(new Variable{word});
            unique_ptr<Variable> a = std::make_unique<Variable>(word);


            // std::unique_ptr<Node> a = new Variable{word};
            node_stack.push(std::move(a));
        }
        else if (word.is_operator())
        {
            if(node_stack.size() < 2)
            {
                throw logic_error("No guilty operator2.");
            }

            std::unique_ptr<Node> rhs = unique_ptr<Node>(std::move(node_stack.top()));
            node_stack.pop();
            std::unique_ptr<Node> lhs = unique_ptr<Node>(std::move(node_stack.top()));

            // std::unique_ptr<Node> lhs = node_stack.top().get();
            node_stack.pop();
            if (word == "+")
            {
                unique_ptr<Addition> a = std::make_unique<Addition>(lhs, rhs);
                // que_ptr<Expression> e(new Expression{});
                // unique_ptr<std::unique_ptr<Node>>  a = new Addition{lhs, rhs};
                // std::unique_ptr<Node> a = new Addition{lhs, rhs};
                node_stack.push(std::move(a));
            }
            else if (word == "-")
            {
                unique_ptr<Subtraction> a = std::make_unique<Subtraction>(lhs, rhs);

                // std::unique_ptr<Node> a = new Subtraction{lhs, rhs};
                node_stack.push(std::move(a));
            }            
            else if (word == "*")
            {
                unique_ptr<Multiplication> a = std::make_unique<Multiplication>(lhs, rhs);

                // std::unique_ptr<Node> a = new Multiplication{lhs, rhs};
                node_stack.push(std::move(a));
            }            
            else if (word == "/")
            {
                unique_ptr<Division> a = std::make_unique<Division>(lhs, rhs);

                // std::unique_ptr<Node> a = new Division{lhs, rhs};
                node_stack.push(std::move(a));
            }
            else if (word == "^")
            {
                unique_ptr<Exponentiation> a = std::make_unique<Exponentiation>(lhs, rhs);

                // std::unique_ptr<Node> a = new Exponentiation{lhs, rhs};
                node_stack.push(std::move(a));
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
<<<<<<< Updated upstream
    Node* a = new Integer{0};
    node_stack.push(a);
=======
    // std::unique_ptr<Node> a = new Integer{10};
    unique_ptr<Integer> a = std::make_unique<Integer>(10);

    // unique_ptr<Integer> a(new Integer{10});

    node_stack.push(std::move(a));
>>>>>>> Stashed changes
}

double Expression::evaluate()
{
<<<<<<< Updated upstream
    return node_stack.top()->evaluate();
=======

    return node_stack.top().get()->evaluate();
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
}
=======
}


// std::unique_ptr<Node> Expression::clone()
// {
//     // expression{"0"};
//     std::unique_ptr<Node> a{};// = new (Node{""});
//     a = node_stack.top()->clone();

    

//     // new Expression{a};
//     // node_stack.push(a);
//     return a;
// }
>>>>>>> Stashed changes
