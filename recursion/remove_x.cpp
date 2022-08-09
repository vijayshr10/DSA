#include <iostream>
using namespace std;

void remove(char str[])
{
    if (str[0]=='\0')
    {
        return;
    }

    if(str[0] != 'x')
    {
        remove(str+1);
    }
    else
    {
        int i=1;
        for(; str[i] != '\0'; i++)
        {
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
        remove(str);
    }
}

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
    char str[100];
    cin>>str;

    int l = length(str);
    cout<<l<<endl;

    remove(str);

    cout<<str<<endl;
   
}