#include <iostream>
using namespace std;

int length(char input[])
{
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) { 
        len++;
    }
    return len;
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    cout<<length(input);
    cout << input << endl;
    return 0;
}
