#include <iostream>
using namespace std;
#include <stack>

// working in online coding ninjas not in pc
void reverseStack(stack<int> &input, stack<int> &extra){
    if(input.size() <= 1){
        return;
    }

    int val = input.top();
    input.pop();

    reverseStack(input, extra);

    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(val);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    
}


// working in computer but not in online
// void reverseStack(stack<int> &input, stack<int> &extra){
//     if(input.size() <= 1){
//         return;
//     }

//     int val = input.top();

//     while(!input.empty()){
//         extra.push(input.top());
//         input.pop();
//     }
//     while(!extra.empty()){
//         input.push(extra.top());
//         extra.pop();
//     }
    
// }




int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}