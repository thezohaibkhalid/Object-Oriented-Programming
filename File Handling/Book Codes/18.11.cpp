

//----------------------------------------------------------------------------------------Example no 18.11--->
//Write a program that reads the records stored in students.txt file and 
//displays them 

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Student {
    int rno;
    char name[50];
    int marks;
};

int main() {
    system ("cls");

    Student s;
    
    ifstream in("c:\\students.txt", ios::binary);
    
    while (!in.eof()) {
        in.read((char*)&s, sizeof(s));
        cout << "Roll No: " << s.rno << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
    }
    
    in.close();
    
    getch();

    return 0;
}
