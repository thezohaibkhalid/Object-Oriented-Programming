#include<iostream>
using namespace std;

class add {
private:
	
public:
	// Default constructor
	add() {
		cout << "This is the 1st default constructor \n";
	}

	// Parameterized constructor to perform addition
	add(int x, int y) {
		cout<<"This is the 2nd default constructor \n";
		cout << "The addition of A and B is " << x + y << endl;
	}
};

int main() {
	float a, b;

	cout << "Enter the value of A: ";
	cin >> a;

	cout << "Enter the value of B: ";
	cin >> b;

	add obj;          // Object obj created using the default constructor
	add(a, b);       // Object created using the parameterized constructor, performs addition

	return 0;
}

