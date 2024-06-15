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
	ifstream in("students.txt", ios::binary);
	while(!in.eof())
	{
		in.read((char*)&s, sizeof(s));
		cout<<"Roll No: "<<s.rno<<endl;
		cout<<"Name: "<<s.name<<endl;
		cout<<"Marks: "<<s.marks<<endl;
	}
	in.close();
}