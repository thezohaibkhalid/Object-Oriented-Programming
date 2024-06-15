//----------------------------------------------------------------------------------------Example no 18.12--->
//Write a program that creates a file to store name and email of the user using 
//structure

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct email {
    char name[20];
    char id[30];
};

int main() {
    system ("cls");

    email user;
    email check;

    cout << "Enter a name: ";
    cin >> user.name;
    
    cout << "Enter the email address: ";
    cin >> user.id;

    ofstream out("c:/email.txt", ios::out | ios::binary);
    out.write((char*)&user, sizeof(struct email));
    out.close();

    cout << endl << "Contents of file are : ";

    ifstream in("c:/email.txt", ios::in | ios::binary);
    in.read((char*)&check, sizeof(struct email));
    
    cout << endl << check.name;
    cout << endl << check.id;
    
    in.close();

    getch();

    return 0;
}