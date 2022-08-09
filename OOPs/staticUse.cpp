#include <iostream>
using namespace std;
#include "staticstudentclass.cpp"

int main()
{
    Student s1(10, 21);
    Student s2(12, 22);

    s1.display();
    s2.display();
    
    cout<<Student :: getTotalStudents()<<endl;



}