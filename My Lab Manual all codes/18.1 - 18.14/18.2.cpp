#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char city[50];
	ofstream file("city.txt");
	for(int i=0; i<5; i++)
	{
		cout<<"Enter the name of any city: ";
		cin>>city;
		file<<city<<"\n";
	}
	file.close();
}