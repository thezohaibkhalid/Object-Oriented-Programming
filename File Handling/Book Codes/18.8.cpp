

//----------------------------------------------------------------------------------------Example no 18.8--->
//Write a program that reads the character from a text file. It counts total number of characters and total number of vowels in the file.

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>

using namespace std;

int main() {
    system ("cls");

    char ch;
    int t = 0, v = 0;

    ifstream in("c:\\chars.txt");

    while (!in.eof()) {
        in.get(ch);
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            v++;
        }

        if (isalpha(ch)) {
            t++;
        }

        cout << ch << endl;
    }

    cout << "Total characters: " << t << endl;
    cout << "Total vowels: " << v << endl;

    in.close();

    getch();

    return 0;
}
