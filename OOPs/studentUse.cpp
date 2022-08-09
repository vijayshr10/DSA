#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){

    // Creating objects Statically
    Student s1;
    Student s2;

    Student s3, s4, s5;

    s1.age = 24;
    s1.rollNumber = 101;

    cout<<s1.age<<endl;
    cout<<s1.rollNumber<<endl;

    // Creating objects dynamically
    Student *s6 = new Student;
    Student *s7 = new Student;

    (*s6).age = 20;
    (*s6).rollNumber = 104;

    s7->age = 22;
    s7->rollNumber = 106;

    cout<<s6->age<<endl;
    cout<<s6->rollNumber<<endl;



    return 0;
}