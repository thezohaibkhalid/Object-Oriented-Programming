/*
Question no 18:- Add and Subtract using Binary Operator Overloading.
*/
#include <iostream>
using namespace std;

class MyNumber {
private:
    int value;

public:
    MyNumber(int val) : value(val) {}

    // Binary addition operator overloading
    MyNumber operator+(const MyNumber& other) {
        return MyNumber(value + other.value);
    }

    // Binary subtraction operator overloading
    MyNumber operator-(const MyNumber& other) {
        return MyNumber(value - other.value);
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyNumber num1(10);
    MyNumber num2(5);

    cout << "Real values:" << endl;
    num1.display();
    num2.display();

    MyNumber sum = num1 + num2; // Using the overloaded + operator
    MyNumber difference = num1 - num2; // Using the overloaded - operator

    cout << "Sum of values:" << endl;
    sum.display();

    cout << "Difference of values:" << endl;
    difference.display();

    return 0;
}
