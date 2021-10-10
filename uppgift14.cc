#include <iostream>
#include "Expression2.h"
#include "token.h"
#include "Operators.h"
#include "postfix.h"


using namespace std;

int main() 
{
    Expression e{};
    string line;
    vector<Expression> exp_vec;

    while (getline(cin, line)) {
        if (line[0] != ':') {

            try{
                Expression e{line};       
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
                cout << e.evaluate() << endl;
            }
            else if(line == ":save")
            {
                exp_vec.push_back(e);
            }
            else if(line == ":list")
            {
                for (int i = 0; i < exp_vec.size(); i++)
                    cout << exp_vec[i].to_infix() <<endl;
            }
            else if(line == ":activate N")
            {
                return 0;
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