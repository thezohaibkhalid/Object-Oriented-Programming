/*
Q#.11: Write a program which takes values in an array and stores it in a pointer, then that pointer prints values of the array.
*/
#include <iostream>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    Array(int size) {
        this->size = size;
        arr = new int[size];
    }


    void inputValues() {
        for (int i = 0; i < size; i++) {
            cout << "Enter value for element " << i+1 << ": ";
            cin >> arr[i];
        }
    }

    void printValues() const {
        cout << "Array values: \n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Array obj(size);

    obj.inputValues();
    obj.printValues();

    return 0;
}
