
//----------------------------------------------------------------------------------------Example no 18.3--->
//Write a program that reads the contents of the file test.txt and displays on the screen

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main() {
    int n;
    char ch;
    double d;

    ifstream file("c:\\test.txt");

    if (!file) {
        cout << "File opening error." << endl;
        exit(1);
    }

    file >> n >> ch >> d;
    cout << "The contents of the file are as follows:" << endl;
    cout << n << endl << ch << endl << d << endl;

    file.close();
    getch();

    return 0;
}
