

//----------------------------------------------------------------------------------------Example no 18.1--->

// #include <iostream>
// #include <fstream>
// #include <conio.h>
// #include <windows.h>
// #include <stdlib.h>

// using namespace std;

// int main() {
//     system("cls");

//     int n = 10;
//     char ch = 'A';
//     double d = 38.125;

//     ofstream file("c:\\test.txt");

//     if (!file) {
//         cout << "File opening error." << endl;
//         exit(1);
//     }

//     file << n << ' ' << ch << ' ' << d;

//     file.close();
//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.2--->
//Write a program that inputs the names of five cities and store them in a file city.txt

// #include <iostream>
// #include <conio.h>
// #include <fstream>
// #include <windows.h>
// using namespace std;

// int main() {
//     system("cls");
//     char city[50];
//     ofstream file("c:\\city.txt");

//     for (int i = 0; i < 5; i++) {
//         cout << "Enter the name of any city: ";
//         cin >> city;
//         file << city << "\n";
//     }

//     file.close();
//     getch();

//     return 0;
// }

//----------------------------------------------------------------------------------------Example no 18.3--->
//Write a program that reads the contents of the file test.txt and displays on the screen

// #include <iostream>
// #include <fstream>
// #include <conio.h>

// using namespace std;

// int main() {
//     int n;
//     char ch;
//     double d;

//     ifstream file("c:\\test.txt");

//     if (!file) {
//         cout << "File opening error." << endl;
//         exit(1);
//     }

//     file >> n >> ch >> d;
//     cout << "The contents of the file are as follows:" << endl;
//     cout << n << endl << ch << endl << d << endl;

//     file.close();
//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.4--->
//Write a program that displays all records from city.txt prepared in previous example

// #include <iostream>
// #include <fstream>

// using namespace std;

// int main() {
//     char city[50];
    
//     ifstream file("c:\\city.txt");

//     if (!file) {
//         cout << "Error in opening file." << endl;
//         exit(1);
//     }

//     cout << "The list of cities is as follows:" << endl;

//     while (!file.eof()) {
//         file >> city;
//         cout << city << endl;
//     }

//     file.close();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.5--->
//Write a program that stored five lines of a string in a file and then displays them 
//on the screen by reading these lines.

// #include <iostream>
// #include <conio.h>
// #include <fstream>

// using namespace std;

// int main() {
//     char str[100];

//     ofstream out("c:\\strings.txt");

//     for (int i = 0; i < 5; i++) {
//         cout << "Enter a string: ";
//         gets(str);  // Note: gets() is not recommended due to security issues.
//         out << str << "\n";
//     }

//     out.close();

//     ifstream in("c:\\strings.txt");

//     while (in.getline(str, 100)) {
//         cout << str << endl;
//     }

//     in.close();

//     getch();

//     return 0;
// }



//----------------------------------------------------------------------------------------Example no 18.6--->
//Write a program that inputs five characters from the user and stores them in a file

// #include <iostream>
// #include <conio.h>
// #include <stdio.h>
// #include <fstream>

// using namespace std;

// int main() {
//     char ch;
    
//     ofstream out("c:\\chars.txt");

//     for (int i = 0; i < 5; i++) {
//         cout << "Enter a character: ";
//         cin >> ch;
//         out.put(ch);
//     }

//     out.close();

//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.7--->
//Write a program that writes a characters from a text file and displays them on screen

// #include <iostream>
// #include <conio.h>
// #include <windows.h>
// #include <stdio.h>
// #include <fstream>

// using namespace std;

// int main() {
//     system ("cls");

//     char ch;

//     ifstream in("c:\\chars.txt");

//     while (!in.eof()) {
//         in.get(ch);
//         cout << ch << endl;
//     }

//     in.close();

//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.8--->
//Write a program that reads the character from a text file. It counts total number of characters and total number of vowels in the file.

// #include <iostream>
// #include <conio.h>
// #include <stdio.h>
// #include <fstream>
// #include <ctype.h>
// #include <windows.h>

// using namespace std;

// int main() {
//     system ("cls");

//     char ch;
//     int t = 0, v = 0;

//     ifstream in("c:\\chars.txt");

//     while (!in.eof()) {
//         in.get(ch);
//         ch = tolower(ch);

//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//             v++;
//         }

//         if (isalpha(ch)) {
//             t++;
//         }

//         cout << ch << endl;
//     }

//     cout << "Total characters: " << t << endl;
//     cout << "Total vowels: " << v << endl;

//     in.close();

//     getch();

//     return 0;
// }



//----------------------------------------------------------------------------------------Example no 18.9--->
//Write a program that inputs five integers and stores it in a file using binary I/O.

// #include <iostream>
// #include <conio.h>
// #include <fstream>
// #include <windows.h>

// using namespace std;

// int main() {
//     system ("cls");
    
//     int n;
    
//     ofstream out("c:\\data.txt", ios::binary);
    
//     for (int i = 1; i <= 5; i++) {
//         cout << "Enter an integer: ";
//         cin >> n;
//         out.write((char*)&n, sizeof(n));
//     }
    
//     out.close();
    
//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.10--->
//Write a program that uses a structure variable to input records of three students and stores it in  students.txt
//in binary I/O. Each record console of Roll No, Name and Marks

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Student {
    int rno;
    char name[50];
    int marks;
};

int main() {
    system ("cls")
    
    Student s;
    
    ofstream out("c:\\students.txt", ios::binary);
    
    for (int i = 1; i <= 3; i++) {
        cout << "Enter your Roll No: ";
        cin >> s.rno;
        
        cout << "Enter your name: ";
        cin >> s.name;
        
        cout << "Enter your marks: ";
        cin >> s.marks;
        
        out.write((char*)&s, sizeof(s));
    }
    
    out.close();
    
    getch();

    return 0;
}


//----------------------------------------------------------------------------------------Example no 18.11--->
//Write a program that reads the records stored in students.txt file and 
//displays them 

// #include <iostream>
// #include <conio.h>
// #include <fstream>

// using namespace std;

// struct Student {
//     int rno;
//     char name[50];
//     int marks;
// };

// int main() {
//     clrscr();

//     Student s;
    
//     ifstream in("c:\\students.txt", ios::binary);
    
//     while (!in.eof()) {
//         in.read((char*)&s, sizeof(s));
//         cout << "Roll No: " << s.rno << endl;
//         cout << "Name: " << s.name << endl;
//         cout << "Marks: " << s.marks << endl;
//     }
    
//     in.close();
    
//     getch();

//     return 0;
// }




//----------------------------------------------------------------------------------------Example no 18.12--->
//Write a program that creates a file to store name and email of the user using 
//structure

// #include <iostream>
// #include <fstream>
// #include <conio.h>

// using namespace std;

// struct email {
//     char name[20];
//     char id[30];
// };

// int main() {
//     clrscr();

//     email user;
//     email check;

//     cout << "Enter a name: ";
//     cin >> user.name;
    
//     cout << "Enter the email address: ";
//     cin >> user.id;

//     ofstream out("c:/email.txt", ios::out | ios::binary);
//     out.write((char*)&user, sizeof(struct email));
//     out.close();

//     cout << endl << "Contents of file are : ";

//     ifstream in("c:/email.txt", ios::in | ios::binary);
//     in.read((char*)&check, sizeof(struct email));
    
//     cout << endl << check.name;
//     cout << endl << check.id;
    
//     in.close();

//     getch();

//     return 0;
// }


//----------------------------------------------------------------------------------------Example no 18.13--->
//Write a program that stores an object to a file country.txt using binary I/O.

// #include <iostream>
// #include <fstream>

// using namespace std;

// class Country {
// private:
//   int id;
//   char name[50];

// public:
//   void get() {
//     cout << "Enter country id: ";
//     cin >> id;
//     cout << "Enter country name: ";
//     cin >> name;
//   }

//   void show() {
//     cout << "Country ID: " << id << endl;
//     cout << "Country Name: " << name << endl;
//   }

//   void toFile(const char* filename) {
//     ofstream out(filename, ios::binary);
//     out.write((char*)&id, sizeof(id));
//     out.write(name, sizeof(name));
//     out.close();
//   }

//   void fromFile(const char* filename) {
//     ifstream in(filename, ios::binary);
//     in.read((char*)&id, sizeof(id));
//     in.read(name, sizeof(name));
//     in.close();
//   }
// };

// void main() {
//   Country cn;
//   ofstream out("c:\\country.txt", ios::binary);
//   cn.get();
//   out.write((char*)&cn, sizeof(cn));
//   out.close;

//   return 0;
// }



//----------------------------------------------------------------------------------------Example no 18.14--->
//Write a program tha: reads the contents of country.txt and display on the screen.


// #include <iostream>
// #include <fstream>

// using namespace std;

// class Country {
// private:
//   int id;
//   char name[50];

// public:
//   void get() {
//     cout << "Enter country id: ";
//     cin >> id;
//     cout << "Enter country name: ";
//     cin >> name;
//   }

//   void show() {
//     cout << "Country ID: " << id << endl;
//     cout << "Country Name: " << name << endl;
//   }
// };

// int main() {
//   Country cn;
//   ifstream in("c:\\country.txt", ios::binary);
//   if (in.is_open()) {
//     in.read((char*)&cn, sizeof(cn));
//     cn.show();
//     in.close();
//   } else {
//     cout << "File not found!" << endl;
//   }

//   return 0;
// }

