/*
What is the output of the C++ program when an object of the derived class is created and its 
show() method is called, considering the use of a pure virtual function show() in the base 
class myclass and the initialization of the protected variable x in the derived class?
*/

/*
If a base class contains a pure virtual function, the base class is considered an abstract 
class. An abstract class cannot be instantiated directly; it's meant to be used as a blueprint 
for derived classes.
*/
#include <iostream>
using namespace std;

class myclass {
public:
    virtual void show() = 0; // Pure virtual function
};

class derived : public myclass {
protected:
    int x;

public:
    derived(int val) : x(val) {}

    void show() {
        cout << "Derived class show(), x = " << x << endl;
    }
};

int main() {
    derived obj(10);
    obj.show();
    return 0;
}
