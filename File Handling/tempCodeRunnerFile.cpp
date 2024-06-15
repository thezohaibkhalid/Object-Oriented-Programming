
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main() {
    clrscr();
    
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
