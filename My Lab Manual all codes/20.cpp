/*
What is the output of the C++ program when a pointer to the Base class is used to call the display() function on an
object of the Derived class, and why does this output occur, considering that the display() function in the Base class
is declared as virtual?
*/

/*
 The output will be determined by the actual type of the object pointed to at runtime. 
 This is an example of runtime polymorphism and dynamic binding, made possible by using virtual functions.
*/

#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "It's of base class display() function. " << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "It's of derived class display() function. " << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->display();
    delete basePtr;
    return 0;
}
