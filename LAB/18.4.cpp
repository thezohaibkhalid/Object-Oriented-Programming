
//----------------------------------------------------------------------------------------Example no 18.4--->
//Write a program that displays all records from city.txt prepared in previous example

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char city[50];
    
    ifstream file("c:\\city.txt");

    if (!file) {
        cout << "Error in opening file." << endl;
        exit(1);
    }

    cout << "The list of cities is as follows:" << endl;

    while (!file.eof()) {
        file >> city;
        cout << city << endl;
    }

    file.close();

    return 0;
}