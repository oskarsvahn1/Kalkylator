#include <iostream>
#include "Expression2.h"
#include "token.h"
#include "Operators.h"
#include "postfix.h"
#include <memory>


using namespace std;

int main() 
{
<<<<<<< Updated upstream
    Expression e{};
    string line;

=======
    // unique_ptr<Expression> e(new Expression{});
    unique_ptr<Expression>e = make_unique<Expression>();

    string line;
    vector<Expression> exp_vec;
>>>>>>> Stashed changes
    while (getline(cin, line)) {
        if (line[0] != ':') {

            try{
<<<<<<< Updated upstream
                Expression e{line};       
=======
                // unique_ptr<Expression> f(new Expression{line});
                e = std::make_unique<Expression>(line);
                // e = std::move(f);       
>>>>>>> Stashed changes
            }
            catch (exception()) {
                throw logic_error("Felaktigt inmatat uttryck, försök igen.");
            }
        }
        else{
            if (line == ":prefix")
            {
                cout << e.to_prefix() << endl;
            }
            else if(line == ":postfix")
            {
                cout << e.to_postfix() << endl;
            }
            else if(line == ":infix")
            {
                cout << e.to_infix() << endl;
            }
            else if(line == ":calc")
            {
<<<<<<< Updated upstream
                cout << e.evaluate() << endl;
=======
                //cout << std::move(e)->evaluate() << endl;
                cout << e->evaluate() << endl;
            }
            else if(line == ":save")
            {
                // exp_vec.push_back(*e);
            }
            else if(line == ":list")
            {
                for (int i = 0; i < exp_vec.size(); i++)
                    cout << exp_vec[i].to_infix() <<endl;
            }
            else if(line.substr(0, 10) == ":activate ")
            {
                int N = stoi(line.substr(10));
                cout<<exp_vec[N].to_postfix()<<endl;
                unique_ptr<Expression> e = make_unique<Expression>(exp_vec[N].to_postfix());
                

                // e = new Expression{exp_vec[N].to_postfix()};
>>>>>>> Stashed changes
            }
            else if(line == ":quit" || line == ":exit")
            {
                return 0;
            }
            else{
                throw logic_error("Felaktigt inmatad kommando, försök igen.");
            }
        }


    }
    return 0;
}