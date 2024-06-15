/*
Q#.13: Create a file using fstream.
*/
#include <iostream>
#include <fstream>
using namespace std;

class File {
private:
    ofstream MyFile;
public:

    void MakeFile() {
        MyFile.open("file.txt");
        if (MyFile.is_open()) {
            MyFile << " Zohaib Khalid ";
            MyFile.close();
            cout << "Written to file successfully." << endl; 
        } else {
            cout << "File is not opened! Error message." << endl; 
        }
    }
};

int main() {
    File obj;
    obj.MakeFile();
    return 0;
}
