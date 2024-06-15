/*
Question no 17:- Create a Unary Operator Overloading Program using postfix.
*/
#include <iostream>
using namespace std;

class MyNumber {
private:
    int value;

public:
    MyNumber(int val) : value(val) {} //given in the previous code that how this is working

    // Postfix increment operator overloading
    MyNumber operator++(int) { //int is spesial indicator (dummy parameter).
        MyNumber temp = *this; // Create a copy of the current object
        value += 1; // Increment the value of the current object
        return temp; // Return the copy of the original object
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyNumber num(5);

    cout << "Real value: ";
    num.display();

    MyNumber result = num++; // Using the overloaded postfix increment operator

    cout << "After postfix increment: ";
    num.display();

    cout << "Value of result: ";
    result.display();

    return 0;
}
