
//----------------------------------------------------------------------------------------Example no 18.6--->
//Write a program that inputs five characters from the user and stores them in a file

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    char ch;
    
    ofstream out("c:\\chars.txt");

    for (int i = 0; i < 5; i++) {
        cout << "Enter a character: ";
        cin >> ch;
        out.put(ch);
    }

    out.close();

    getch();

    return 0;
}
