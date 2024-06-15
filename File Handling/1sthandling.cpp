#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the file for writing
    ofstream outputFile;
    outputFile.open("zohaib.txt");

    // Check if the file was opened successfully
    if (outputFile.is_open()) {
        // Write data to the file
        outputFile << "I am the Zohaib Khalid." << endl;
        outputFile << "Successfull !" << endl;

        // Close the file after writing
        outputFile.close();
        cout << "Data written to the file successfully." << endl;
    } else {
        cout << "Error opening the file for writing." << endl;
    }

    return 0;
}



// // outputFile.open(filename);

// //     if (outputFile.is_open()) {




// #include <iostream>
// #include <fstream>
// using namespace std;

// void writeToFile(const string& filename) {
//     ofstream outputFile;
//     outputFile.open(iam.txt);

//     if (outputFile.is_open()) {
//         outputFile << "Zohaib, this is a sample text." << endl;
//         outputFile << "18" << endl;
//         outputFile << "3.14" << endl;
//         outputFile << "This code is Runing" << endl;
//         outputFile.close();
//         cout << "Data written to the file successfully." << endl;
//     } else {
//         cout << "Error opening the file for writing." << endl;
//     }
// }

// void readFromFile(const string& filename) {
//     ifstream inputFile;
//     inputFile.open(iam.txt);

//     if (inputFile.is_open()) {
//         string line;
//         while (getline(inputFile, line)) {
//             cout << line << endl;
//         }
//         inputFile.close();
//     } else {
//         cout << "Error opening the file for reading." << endl;
//     }
// }

// int main() {
//     const string filename = "data.txt";

//     // Writing to the file
//     writeToFile(filename);

//     // Reading from the file
//     cout << "Contents of the file:" << endl;
//     readFromFile(filename);

//     return 0;
// }
