/*
Question no 19:-  What is the output of the C++ program when a pointer to the Base class is used to call the display() 
function on an object of the Derived class, and why does this output occur?
*/

/*
When a pointer of base class is used to call the display() function of the derived class the output 
depends on whether the display() function in the Base class is declared as virtual or not.
*/

//Without virtual (It's base)

#include <iostream>
using namespace std;

// class Base {
// public:
//     void display() {
//         cout << "It's of base class display() function. " << endl;
//     }
// };

// class Derived : public Base {
// public:
//     void display() {
//         cout << "It's of derived class display() function. " << endl;
//     }
// };


// By using Virtual (It's derived)


class Base {
public:
    virtual void display() {
        cout << "It's of base class display() function" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "It's of derived class display() function" << endl;
    }
};


int main() {
    Base* basePtr = new Derived();
    basePtr->display();
    delete basePtr;
    return 0;
}