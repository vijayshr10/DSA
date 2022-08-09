#include <iostream>
using namespace std;
#include "Fractionclass.cpp"

int main()
{
    // Fraction f1(10,2);
    // Fraction f2(15,4);

    // f1.add(f2);
    // f1.print();
    // f2.print();

    // f1.multiply(f2);
    // f1.print();
    // f2.print();

    /*
    Fraction f3 = f1 + f2;
    f1.print();
    f2.print();
    f3.print();

    Fraction f4 = f1 * f2; 
    f4.print();

    if(f1 == f2){
        cout<<"Equal"<<endl;
    }
    else{
        cout<<"Not equal"<<endl;
    }
    */

    // Fraction f1(10,2);
    // Fraction f2(15,4);

    // f1.print();
    // ++f1;
    // f1.print();

    // Fraction f3 = ++f1;
    // f1.print();
    // f3.print();

    // f1.print();
    // Fraction f3 = ++(++f1);
    // // f1.print();
    // // f3.print();

    // f1.print();
    // Fraction f3 = f1++;
    // f1.print();
    // f3.print();

    // // (i++)++; nesting for post increment id not allowed;

    Fraction f1(10,3);
    Fraction f2(5,2);
    // f1 += f2;
    // f1.print();
    // f2.print();
    (f1 += f2) += f2;
    f1.print();
    f2.print();









}