#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool isBalanced(string expression){
    if(expression[0] == ')' || expression[1] == '\0'){
        return false;
    }

    stack<char> s;
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '('){
            s.push(expression[i]);
        }
    }

    for(int i =0; i<expression.length(); i++){
        if(expression[i] == ')'){
            s.pop();
        }
    }

    return s.empty();
}


int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}