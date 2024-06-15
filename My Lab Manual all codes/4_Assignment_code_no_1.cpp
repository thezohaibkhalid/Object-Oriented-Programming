//
// Created by zohaib on 29/05/2023.
//

/*Task no 1:-->

Design a program that defines a class named "Number" with two data members, "num" of type float and
"result" of type int. The program should include four functions that can be used to calculate the factorial
of a number and display the result:
•	A function to check if the number is a whole number or not.
•	A function to check if the number is positive or not.
•	A function to calculate the factorial of the given number.
•	A function to display the input number and its factorial. Please note that to calculate
    the factorial of a number, it must be positive and a whole number. If any of these conditions
    are not met, the program cannot determine the factorial.
*/


#include<iostream>
using namespace std;

class Number {
private:
    float num; // private data member to store the input number
    //  int result;

public:
    // Function to check if number is a whole number
    bool WholeNum() {
        int wholenum = (int)num; // Typecast num to an int to remove decimal part
        if (num == wholenum){//checks if the original number is equal to the original value of the number
            return true; // returns true if number is a whole number
        }
        else{
            return false; // returns false if number is not a whole number
        }
    }

    // Function to check if number is positive
    bool PositiveNum() {
        if(num > 0){
            return true; // returns true if number is positive
        }
        else {
            return false; // returns false if number is not positive
        }
    }

    // Function to calculate the factorial of the given number
    int FactCal() {
        int fact = 1;
        for(int i = 1; i <= num; i++) {
            fact *= i; // calculates the factorial of the number
        }
        return fact; // returns the calculated factorial
    }

    // Function to display the result
    void DisplayResult() {
        cout << "Number : " << num << endl; // displays the input number
        if(WholeNum()){
            cout << "It is a whole number " << endl; // displays if number is a whole number
        }
        else {
            cout << "It is not a whole number." << endl; // displays if number is not a whole number
        }
        if(PositiveNum()) {
            cout << "It is a positive number." << endl; // displays if number is positive
        }
        else {
            cout << "It is not a positive number." << endl; // displays if number is not positive
        }
        cout << "Factorial: " << FactCal() << endl; // displays the calculated factorial
    }

    // Function to set the value of num
    void setNum(float n) {
        num = n; // sets the value of input number
    }
};

int main(){
    float num;
    cout << "Enter a Number : ";
    cin >> num;

    Number xyz; // creates an object of the Number class
    xyz.setNum(num); // sets the input number in the object
    xyz.DisplayResult(); // calls the Displayresult() function to display the result
    return 0;
}
