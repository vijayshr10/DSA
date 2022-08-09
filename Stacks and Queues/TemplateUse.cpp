#include <iostream>
using namespace std;
#include "TemplateClass.cpp"

int main(){

    Pair<int, double> p1;
    p1.setX(10);
    p1.setY(100.359);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;


    // Triplets

    Pair<Pair<int, double>, int> p2;

    p2.setX(p1);
    p2.setY(50);

    cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY()<<endl;

}