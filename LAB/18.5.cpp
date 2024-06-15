
//----------------------------------------------------------------------------------------Example no 18.5--->
//Write a program that stored five lines of a string in a file and then displays them 
//on the screen by reading these lines.

#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main() {
    char str[100];

    ofstream out("c:\\strings.txt");

    for (int i = 0; i < 5; i++) {
        cout << "Enter a string: ";
        gets(str);  // Note: gets() is not recommended due to security issues.
        out << str << "\n";
    }

    out.close();

    ifstream in("c:\\strings.txt");

    while (in.getline(str, 100)) {
        cout << str << endl;
    }

    in.close();

    getch();

    return 0;
}