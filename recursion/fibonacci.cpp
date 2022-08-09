#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    int first = fib(n-1);
    int sec = fib(n-2);

    return first + sec;

}
int main()
{
    cout<<fib(3)<<endl;

    return 0;
}