


//----------------------------------------------------------------------------------------Example no 18.9--->
//Write a program that inputs five integers and stores it in a file using binary I/O.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    system ("cls");
    
    int n;
    
    ofstream out("c:\\data.txt", ios::binary);
    
    for (int i = 1; i <= 5; i++) {
        cout << "Enter an integer: ";
        cin >> n;
        out.write((char*)&n, sizeof(n));
    }
    
    out.close();
    
    getch();

    return 0;
}
