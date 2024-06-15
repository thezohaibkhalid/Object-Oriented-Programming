//
// Created by zohaib on 29/05/2023.
//
/*Q#.2:Write a class called rectangle. Your task is to store the length and width of the rectangle.
        Write a member function called increment that will add 1 to the value of length and width.
        Also write a function that will compute the area of the rectangle. Finally write a constant
        function that will display the length, width and area of the rectangle. Demonstrate the use
        of the object in the main function. Make sure that the function names are meaningful.*/
#include <iostream>
using namespace std;

class rectangle{
private:
    float length, width;
public:
    rectangle(){
        cout<<"Enter the length of the Rectangle : ";
        cin>>length;
        cout<<"Enter the Width of the Rectangle : ";
        cin>>width;
        length++;
        width++;
    }
    float calArea(){

        return length*width;
    }
    void display(){
        cout<<"The Area of the rectangle is eqaul to "<< calArea();
        cout<<"\nThe length of the rectangle is equal to "<<length;
        cout<<"\nThe width of the rectangle is equal to "<<width;
    }
};
int main(){
    rectangle qwe;
    qwe.display();
    return 0;
}