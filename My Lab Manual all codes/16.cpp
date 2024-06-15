/*
Q#.16: Create a Unary Operator Overloading Program using prefix.
*/
#include <iostream>
using namespace std;

class MyNumber {
private:
    int value;

public:
    //MyNumber(int val) : value(val) {}
    MyNumber(int val){
        value = val;
    }

    // Prefix increment operator overloading
    MyNumber operator++() {
        value += 1;
        return *this; // used to return the modified object after performing an operation
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyNumber num(5);

    cout << "Real value: ";
    num.display();

    ++num; 
    //++num; //changing it will change the number of after profix increament

    cout << "After prefix increment: ";
    num.display();

    return 0;
}
