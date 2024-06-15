#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ch;
	ifstream in("chars.txt");
	while(!in.eof())
	{
		in.get(ch);
		cout<<ch<<endl;
	}
	in.close();
}