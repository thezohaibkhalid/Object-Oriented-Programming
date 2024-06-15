#include <iostream>
#include <fstream>
using namespace std;
struct Student
{
	int rno;
	char name[50];
	int marks;
};
int main()
{
	Student s;
	ofstream out("student.txt", ios::binary);
	for(int i=1; i<=3; i++)
	{
		cout<<"Enter your roll no: ";
		cin>>s.rno;
		cout<<"Enter your name: ";
		cin>>s.name;
		cout<<"Enter your marks: ";
		cin>>s.marks;
		out>write((char*)&s, sizeof(s));
	}
	out.close();
}