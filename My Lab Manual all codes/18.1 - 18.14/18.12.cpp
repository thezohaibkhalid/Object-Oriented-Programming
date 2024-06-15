#include <iostream>
#include <fstream>
using namespace std;
struct email
{
	char name[20];
	char id[30];
};
int main()
{
	email user;
	email check;
	cout<<"Enter a name: ";
	cin>>user.name;
	cout<<"Enter the email address: ";
	cin>>user.id;
	ofstream out("email.txt", ios::out | ios::binary);
	out.write((char*)&user, sizeof(struct email));
	out.close();
	cout<<endl<<"Contents of the file are: ";
	ifstream in ("email.txt", ios::in | ios::binary);
	in.read((char*)&check, sizeof(struct email));
	cout<<endl<<check.name;
	cout<<endl<<check.id;
	in.close();
};
