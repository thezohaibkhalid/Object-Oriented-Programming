#include<iostream>
using namespace std;

class Number{
private:
	int a;

public:
	// Default constructor
	Number(){
		a = 0; // Initialize 'a' to 0
	}

	// Parameterized constructor
	Number(int num){
		a = num;
	}

	// Copy constructor
	//When no copy constructor is found compiler supplies it's own copy constructor
	/*Number(Number &obj){
		cout << "This is the copy constructor \n";
		a = obj.a;
	}*/

	// Member function to display the value of 'a'
	void display(){
		cout << "The number for this object is " << a << endl;
	}
};

int main(){
	Number x;     // Object x is created using the default constructor
	Number y;     // Object y is created using the default constructor
	Number z(129);  // Object z is created using the parameterized constructor and initialized with 129

	x.display();  // Display the value of 'a' for object x
	y.display();  // Display the value of 'a' for object y
	z.display();  // Display the value of 'a' for object z

//	Number z1 = z;  // Object z1 is created as a copy of z using the copy constructor
	//or 
	Number z1(z);   //Copy constructor invoked
	z1.display();   // Display the value of 'a' for object z1

	return 0;
}

