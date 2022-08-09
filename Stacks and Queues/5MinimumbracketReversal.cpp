#include <iostream>
#include <string>
using namespace std;


#include <stack>
int countBracketReversals(string input) {
    if(input.length() % 2 == 1){
        return -1;
    }

    stack<char> s;

    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == '{'){
            s.push(input[i]);
        }
        else
        {
            if(s.empty()){
                s.push(input[i]);
            }
            else{
                if(s.top() == '{'){
                    s.pop();
                }
                else{
                    s.push(input[i]);
                }
            }
        }   
    }
    int count = 0;
    while(!s.empty()){
        char c1, c2;
        c1 = s.top();
        s.pop();
        c2 = s.top();

        if(c1 == c2){
            count++;
            s.pop();
        }
        else{
            count = count + 2;
            s.pop();
        }
    }

    return count;

}


int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}