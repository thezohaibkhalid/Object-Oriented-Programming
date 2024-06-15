#include<iostream>
using namespace std;

int myFunction()
{
	int localVar=10;//Local Variable
	cout<<"Local Variable : "<<localVar<<endl;
}

int main()
{
	myFunction();
	//Local Variable is not accessible here
	return 0;
}

/*
Local Variables:
   - Local variables are declared within a specific block of code, such as a function or a loop.
   - They are only accessible within the block in which they are defined.
   - Local variables are typically used to store temporary data or intermediate results.

*/
