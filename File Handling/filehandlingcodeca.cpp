#include <iostream>
#include <fstream>
using namespace std;
// int main()
// {
//     fstream obj; //We use fstream for both reading and writing, in for reading and out for writing.
//      obj.open("zohaib.txt",ios:out); /*similarly if (input file) for reading and of stream (outputfile) for writing
//  }--->Trunk mode is used to check out the file that if a file exsists there from before and if it
//  does exsist then it deleted all the data in text file 
//  }--->app mode (Append) in this case if a file with a same name exeits from before then by using
//  this mode we are not deleting the data of the file, we are pushing that data to the end of
//  the file
//  )--->ate mode (Seek)
//  }--->Binary mode is used to specify in C++ that we are working with a binary file
//  */
//----------------------->>>>>>>>>Example of ate<<<<<<<<<-------------



using namespace std;

int main() {
    ofstream file("example.txt", ios::app);

    if (file.is_open()) {
        // The file is opened in append mode.
        cout<<"file opened ";
        file << "This is a new line.\n";
        file.close();
    } else {
        cout << "Failed to open the file." << endl;
    }

    return 0;
}
