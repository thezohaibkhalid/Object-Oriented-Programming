//
// Created by zohaib on 29/05/2023.
//
/*
Task no 3:-->

Write a C++ Program to implement a sphere class with appropriate members and member function to find
the surface area and the volume. (Surface = 4 π r2 and Volume = 4/ 3 π r3 ).
*/

#include <iostream>
using namespace std;

class Sphere {
private:
    float radius;

public:
    // Constructor to take input from the user and initialize the value of radius
    Sphere(){
        cout << "Enter the radius of the sphere: ";
        cin >> radius;
    }

    // Function to calculate the surface area of the sphere and return the value
    float SurfaceArea() {
        float surfaceArea = 4 * 3.14 * radius * radius;
        return surfaceArea;
    }

    // Function to calculate the volume of the sphere and return the value
    float Volume() {
        float volume = (4.0 / 3.0) * 3.14 * radius * radius * radius;
        return volume;
    }
};

int main() {
    // Create an object of the Sphere class
    Sphere xyz;

    // Call the SurfaceArea function and display the output
    cout << "Surface Area of the sphere is: " << xyz.SurfaceArea() << endl;

    // Call the Volume function and display the output
    cout << "Volume of the sphere is: " << xyz.Volume() << endl;

    return 0;
}

