
//----------------------------------------------------------------------------------------Example no 18.1--->

//Write a program that writes 3 character in a file using formatted I/O .

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main() {
    system("cls");

    int n = 10;
    char ch = 'A';
    double d = 38.125;

    ofstream file("test.txt");

    if (!file) {
        cout << "File opening error." << endl;
        exit(1);
    }

    file << n << ' ' << ch << ' ' << d;

    file.close();
    getch();

    return 0;
}
