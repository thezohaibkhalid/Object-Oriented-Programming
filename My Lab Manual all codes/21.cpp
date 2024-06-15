/*
What will be the output of the C++ program provided, which involves a base class myclass, a derived 
class derived, and a pointer to the base class pointing to an object of the derived class, considering 
the virtual function show() in the base class?
*/
#include <iostream>
using namespace std;

class myclass {
public:
    virtual void show() {
        cout << "BIt's of base class show() function. " << endl;
    }
};

class derived : public myclass {
public:
    void show() {
        cout << "It's of derived class show() function. " << endl;
    }
};

int main() {
    myclass* ptr = new derived();
    ptr->show();
    delete ptr;
    return 0;
}
