#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n;
	char ch;
	double d;
	ifstream file("text.txt");
	if(!file)
	{
		cout<<"File opening error";
		exit(1);
	}
	file>>n>>ch>>d;
	cout<<"the contents of file are as follows: "<<endl;
	cout<<n<<endl<<ch<<endl<<d<<endl;
	file.close();
	return 0;
}
