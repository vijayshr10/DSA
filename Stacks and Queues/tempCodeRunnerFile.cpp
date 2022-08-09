void reverseStack(stack<int> &input, stack<int> &extra){
    if(input.size() <= 1){
        return;
    }

    int val = input.top();

    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    
}