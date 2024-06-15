//
// Created by zohaib on 29/05/2023.
//
/*Task no 2--->

Design a program that uses the "Geometry" class. The program should prompt the user to enter
the length and width of a shape. If both values are equal, the program should call the "square"
function to calculate the area and perimeter of a square. Otherwise, it should call the "rectangle"
function to calculate the area and perimeter of a rectangle.
*/

#include <iostream>
using namespace std;

// Define a class called Geometry
class Geometry {
private:
    float length, width; // Declare two private data members representing the length and width of the shape

public:
    // Defining a constructor to initialize the data members of the object
    Geometry() {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
    }

    // A function to calculate and display the area and perimeter of a square
    void square() {
        float area = length * length;
        float perimeter = 4 * length;
        cout << "Area of square: " << area << endl;
        cout << "Perimeter of square: " << perimeter << endl;
    }

    // A function to calculate and display the area and perimeter of a rectangle
    void rectangle() {
        float area = length * width;
        float perimeter = 2 * (length + width);
        cout << "Area of rectangle: " << area << endl;
        cout << "Perimeter of rectangle: " << perimeter << endl;
    }

    // A function to display the area and perimeter based on whether it is a square or a rectangle
    void display(){
        if (length == width) {
            square();
        } else {
            rectangle();
        }
    }
};

// Main function
int main(){

    // Create an object of the Geometry class with the given length and width
    Geometry xyz;

    // Display the area and perimeter of the shape
    xyz.display();

    // End the program and return 0
    return 0;
}

