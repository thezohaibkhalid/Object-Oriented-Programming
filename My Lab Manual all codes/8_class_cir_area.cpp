//
// Created by zohaib on 29/05/2023.
//
/*Q#.7:Create a Class named as Circle. Create a data member named as radius. Create member functions
to calculate area of circle and circumference of the circle.*/

#include <iostream>
using namespace std;

class Circle{
private:
    float radius;
public:
    void getter(){
        cout<<"Enter the Radius of the circle :";
        cin>>radius;
    }
    void calArea(){
        cout<<"The area of the circle is Equal to "<<3.1415*radius*radius;
    }
    void calCir(){
        cout<<"\nThe Circumference of the circle is equal to "<<3.1416*radius;
    }
};

int main(){
    Circle xyz;
    xyz.getter();
    xyz.calArea();
    xyz.calCir();
    return 0;
}