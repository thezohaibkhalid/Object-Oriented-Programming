#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char city[50];
	ifstream file("text.txt");
	if(!file)
	{
		cout<<"Error in opening file";
		exit(1);
	}
	cout<<"The list of cities is as follows: "<<endl;
	while(!file.eof())
	{
		file>>city;
		cout<<city<<endl;
	}
	file.close();
}