

//----------------------------------------------------------------------------------------Example no 18.7--->
//Write a program that writes a characters from a text file and displays them on screen

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    system ("cls");

    char ch;

    ifstream in("c:\\chars.txt");

    while (!in.eof()) {
        in.get(ch);
        cout << ch << endl;
    }

    in.close();

    getch();

    return 0;
}
