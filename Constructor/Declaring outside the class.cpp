#include<iostream>
using namespace std;

class student {
private:
    int rollno;
    char name[20];

public:
    student();  // Implementation of member function
    void putdata();  // Corrected declaration of member function
};

student::student() {
    cout << "Enter the Roll number: ";
    cin >> rollno;
    cout << "Enter the name: ";
    cin >> name;
}

void student::putdata() {
    cout << "Roll number: " << rollno << endl;
    cout << "Name: " << name << endl;
}

int main() {
    student obj;
    obj.putdata();  // Corrected syntax to call putdata()
    return 0;
}

