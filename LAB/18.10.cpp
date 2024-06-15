

//----------------------------------------------------------------------------------------Example no 18.10--->
//Write a program that uses a structure variable to input records of three students and stores it in  students.txt
//in binary I/O. Each record console of Roll No, Name and Marks
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
    system("cls");

    Student s;

    ofstream out("students.txt", ios::binary);

    for (int i = 1; i <= 3; i++) {
        cout << "Enter your Roll No: ";
        cin >> s.rno;

        cin.ignore(); // Clear newline from previous input

        cout << "Enter your name: ";
        cin.getline(s.name, sizeof(s.name)); // Read entire line for name

        cout << "Enter your marks: ";
        cin >> s.marks;

        out.write((char*)&s, sizeof(s));
    }

    out.close();

    getch();
}
