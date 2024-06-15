/*
Q#.15: Output a string from the file.
*/
#include <iostream>
#include <fstream>
using namespace std;

class File {
private:
    ifstream MyFile;

public:
    void ReadFile() {
        MyFile.open("file1.txt"); 
        if (MyFile.is_open()) {
            string line; 
            getline(MyFile, line); 
            cout << "String from file: " << line << endl;
            MyFile.close();
            cout << "String Reading from the file successfull ";
        }else {
            cout << "File not opened! Error Message" << endl;
        }
    }
};

int main() {
    File obj;
    obj.ReadFile();
    return 0;
}
