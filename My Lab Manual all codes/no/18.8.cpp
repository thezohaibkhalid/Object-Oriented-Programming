#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ch;
	int t, v;
	t=v=0;
	ifstream in("chars.txt");
	while(!in.eof())
	{
		in.get(ch);
		ch=tolower(ch);
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
		{
			v++;
			t++;
			cout<<ch<<endl;
		}
	}
	cout<<"Total Characters: "<<t<<endl;
	cout<<"Total Vowels: "<<v<<endl;
	in.close();
}