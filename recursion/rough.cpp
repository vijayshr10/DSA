#include <bits/stdc++.h>

using namespace std;

int length(char str[])
{
    if (str[0]=='\0')
    {
        return 0;
    }

    int smalllength = length(str+1);
    return 1 + smalllength;
}

int main()
{
   int l = INT_MIN;
   cout<<l;
}