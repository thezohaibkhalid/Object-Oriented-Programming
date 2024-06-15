/*
Input a string into the file.
*/
#include <iostream>
#include <fstream>
using namespace std;

class File {
private:
    ofstream MyFile;
public:
    void MakeFile() {
        MyFile.open("file1.txt");
        if (MyFile.is_open()) {
            MyFile << " My name is  Zohaib Khalid ";
            MyFile.close();
            cout << "String written to file successfully.";
        } else {
            cout << "File is not opened! Error message.";
        }
    }
};

int main() {
    File obj;
    obj.MakeFile();
    return 0;
}