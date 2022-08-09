#include <iostream>
#include <stack>
using namespace std;


//  Without Using Stack  --- time n^2

// int* stockSpan(int input[], int size){
//     int *span = new int[size];
//     int count = 0;

//     for(int  i=0; i<size; i++){
//        count = 1;
//        for(int j=i-1; j>=0; j--){
//            if(input[j] < input[i]){
//                count++;
//            }
//            else{
//                break;
//            }
//        }
//        span[i] = count;
//     }

//     return span;
// }

int* stockSpan(int price[], int size){
    int *span = new int[size];
    stack<int> s;
    span[0] = 1;
    s.push(0);

    for(int i=1; i<size; i++)
    {
        while(!s.empty() && price[i] > price[s.top()])
        {
            s.pop();
        }

        if(s.empty())
        {
            span[i] = i+1;
        }
        else{
            span[i] = i - s.top();
        }
        s.push(i);
    }

    return span;

}



int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}