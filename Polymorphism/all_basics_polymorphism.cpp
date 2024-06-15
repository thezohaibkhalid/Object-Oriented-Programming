/*
1------------>
Function Overloading (Compile-time Polymorphism):
Function overloading allows defining multiple functions with the same name but different 
parameter lists. The correct function is selected based on the arguments at compile time.*/

// #include <iostream>
// using namespace std;

// class OverloadExample {
// public:
//     void print(int value) {
//         cout << "Printing an integer: " << value << endl;
//     }

//     void print(double value) {
//         cout << "Printing a double: " << value << endl;
//     }
// };

// int main() {
//     OverloadExample obj;
//     obj.print(42);        // Invokes the int version of the print function
//     obj.print(3.14);      // Invokes the double version of the print function
//     return 0;
// }

/*
2------------>
Method Overriding (Run-time Polymorphism):
Method overriding allows a derived class to provide a specific implementation of a 
function that is already defined in the base class. The correct function is determined 
at run-time based on the object's actual type.*/

// #include <iostream>
// using namespace std;

// class Shape {
// public:
//     virtual void draw() {
//         cout << "Drawing a generic shape." << endl;
//     }
// };

// class Circle : public Shape {
// public:
//     void draw() override {
//         cout << "Drawing a circle." << endl;
//     }
// };

// int main() {
//     Shape* shapePtr;

//     Circle circle;
//     shapePtr = &circle;
//     shapePtr->draw();   // Invokes the overridden draw function for Circle

//     Shape genericShape;
//     shapePtr = &genericShape;
//     shapePtr->draw();   // Invokes the base class draw function

//     return 0;
// }

/*
3------------>
Operator Overloading:
Operator overloading allows defining custom behaviors for operators when used with objects of a class.*/

// #include <iostream>
// using namespace std;

// class Complex {
// public:
//     int real;
//     int imag;

//     Complex operator+(const Complex& other) {
//         Complex result;
//         result.real = this->real + other.real;
//         result.imag = this->imag + other.imag;
//         return result;
//     }
// };

// int main() {
//     Complex c1, c2, c3;
//     c1.real = 3;
//     c1.imag = 4;

//     c2.real = 1;
//     c2.imag = 2;

//     c3 = c1 + c2;  // Invokes the overloaded + operator
//     cout << "Result: " << c3.real << " + " << c3.imag << "i" << endl;

//     return 0;
// }

#include <iostream>

class Base {
public:
    void baseFunction() {
        std::cout << "Base class function" << std::endl;
    }
};

class Derived : public Base {
public:
    void derivedFunction() {
        std::cout << "Derived class function" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    derivedObj.baseFunction(); // Calling the function from the base class using derived-class object
    return 0;
}

