//
// Created by zohaib on 29/05/2023.
//
/*Q#.9: Create a Class named as Complex. Create Data members named as real and imaginary.
1. Create a function to get values from the user.
2. Create a function to add two complex numbers.
3. Create a function to subtract two complex numbers.*/

#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    void getValues() {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> imaginary;
    }

    void add(Complex other) {
        real += other.real;
        imaginary += other.imaginary;
    }

    void subtract(Complex other) {
        real -= other.real;
        imaginary -= other.imaginary;
    }

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }
};

int main() {
    Complex xyz1, xyz2;
    cout << "Enter the first complex number:\n";
    xyz1.getValues();
    cout << "Enter the second complex number:\n";
    xyz2.getValues();

    xyz1.add(xyz2);
    xyz2.subtract(xyz1);

    cout << "Sum: " << xyz1.getReal() << " + " << xyz1.getImaginary() << "i\n";
    cout << "Difference: " << xyz2.getReal() << " + " << xyz2.getImaginary() << "i\n";

    return 0;
}
