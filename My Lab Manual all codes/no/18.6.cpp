#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ch;
	ofstream out("chars.txt");
	for(int i=0; i<5; i++)
	{
		cout<<"Enter a character: ";
		cin>>ch;
		out.put(ch);
	}
	out.close();
}