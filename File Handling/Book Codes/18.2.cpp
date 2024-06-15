
//----------------------------------------------------------------------------------------Example no 18.2--->
//Write a program that inputs the names of five cities and store them in a file city.txt

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    system("cls");
    char city[50];
    ofstream file("c:\\city.txt");

    for (int i = 0; i < 5; i++) {
        cout << "Enter the name of any city: ";
        cin >> city;
        file << city << "\n";
    }

    file.close();
    getch();

    return 0;
}