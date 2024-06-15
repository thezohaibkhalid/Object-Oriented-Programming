/*
What is the output of the C++ program when an object of class3 is created and its inc() 
method is called, considering the use of virtual inheritance, the inc() method override 
in various derived classes, and the shared variable x from the base class class1?
*/
#include <iostream>
using namespace std;

// Base class
class class1 {
public:
    int x;
    class1() : x(1) {}
};

// Derived class 1 virtually inheriting from class1
class class2 : virtual public class1 {
public:
    void inc() {
        x++; // Increment x by 1
    }
};

// Derived class 2 virtually inheriting from class1
class class3 : virtual public class1 {
public:
    void inc() {
        x += 2; // Increment x by 2
    }
};

// Derived class inheriting from class2 and class3
class class4 : public class2, public class3 {
public:
    void inc() {
        x += 3; // Increment x by 3
    }
};

int main() {
    class4 obj; // Create an object of class4
    obj.inc();  // Call the inc() method of class4
    cout << "Final value of x: " << obj.x << endl; // Print the final value of x
    return 0;
}
