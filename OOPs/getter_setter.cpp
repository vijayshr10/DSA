#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){

    Student s1;
    Student *s2 = new Student;

    s1.rollNumber = 11;
    s1.setAge(25); // setting age

    (*s2).rollNumber = 15;
    (*s2).setAge(20);

    s1.display();
    (*s2).display();

    int a = s1.getAge();
    cout<<a;



}
