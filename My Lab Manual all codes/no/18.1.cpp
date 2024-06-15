#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
	int n=10;
	char ch= '*';
	double d= 38.125;
	ofstream file("text.txt");
	if(!file)
	{
		cout<<"File opening error.";
		exit(1);
		
	}
	file<<n<<" "<<ch<<" "<<d;
	file.close();
	cout << "Written Successfully ! ";


}
