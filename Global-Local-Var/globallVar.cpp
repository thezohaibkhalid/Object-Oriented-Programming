#include<iostream>
using namespace std;

int globalVar=30;//Global Variable declaration and initialization
int myFunction()
{
	cout<<"Global Variable : "<<globalVar<<endl;
}

int main()
{
	myFunction();
	cout<<"GLobal Variable outside the function : "<<globalVar<<endl;
	
	globalVar=40;//Global Variable can be modified anywhere in the program 
	cout<<"Global Variable after modification : "<<globalVar;
	return 0;
}

/*
Global Variables:
   - Global variables are declared outside of any function or block, making them accessible 
     throughout the entire program.
   - They have a global scope and can be accessed by any function or block within the program.
   - Global variables are typically used to store data that needs to be accessed by multiple functions.
   
*/
