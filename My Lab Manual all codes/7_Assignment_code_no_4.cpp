//
// Created by zohaib on 29/05/2023.
//


/*Task no 4:-->
Design a menu-driven program that enables users to perform arithmetic operations on two numbers. The program
should provide the options to add (+), subtract (-), multiply (*), or divide (/) and prompt users to input the
numbers. In addition, the program should have the following functions:
1.	"showChoice" function that displays the options available to the user and provides 
     instructions on how to enter the data.
2.	"add" function that takes two arguments as input and returns their sum.
3.	"subtract" function that takes two arguments as input and returns their difference.
4.	"multiply" function that takes two arguments as input and returns their product.
5.	"divide" function that takes two arguments as input and returns their quotient.

*/

#include<iostream>
using namespace std;

class Calculator {
private:
    float num1, num2;
public:

    Calculator() {
        int choice;
        cout << " ===============================================" << endl;
        cout << "|            Arithmetic Operations              |" << endl;
        cout << " ===============================================" << endl;
        cout << "|  Operation   |        Symbol         |  Code  |" << endl;
        cout << " ===============================================" << endl;
        cout << "|   Addition   |          +            |   1    |" << endl;
        cout << "| Subtraction  |          -            |   2    |" << endl;
        cout << "|Multiplication|          *            |   3    |" << endl;
        cout << "|   Division   |          /            |   4    |" << endl;
        cout << " ===============================================" << endl;
        cout<<"Enter choice (1-4)\n";
        cout<<"-->   ";
        cin >> choice;
        cout << "Enter 1st Number : ";
        cin >> num1;
        cout<<endl;
        cout << "Enter 2nd Number : ";
        cin >> num2;
        cout<<endl;

        switch(choice) {
            case 1: {
                cout << "The addition of given numbers is: " << add(num1, num2) << endl;
                break;
            }
            case 2: {
                cout << "The Substraction of given numbers is: " << sub(num1, num2) << endl;
                break;
            }
            case 3: {
                cout << "The Multiplication of given numbers is: " << multiply(num1, num2) << endl;
                break;
            }
            case 4: {
                cout << "The Division of the given numbers is: " << div(num1, num2) << endl;
                break;
            }
            default:{
                cout<<"Invalid choice";
                break;
            }
        }
    }

    float add(float num1, float num2) {
        return (num1 + num2);
    }
    float sub(float num1, float num2) {
        return (num1 - num2);
    }
    float multiply(float num1, float num2) {
        return (num1 * num2);
    }
    float div(float num1, float num2) {
        return (num1 / num2);
    }
};

int main() {
    Calculator xyz;
    return 0;
}
