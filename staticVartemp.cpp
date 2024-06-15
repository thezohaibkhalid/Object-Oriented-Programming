#include<iostream>
using namespace std;
 class MyClass {
     public:
       static int count; // Declaration of a static variable
     };

     int MyClass::count = 0; // Definition of the static variable

     int main() {
       MyClass obj1;
       MyClass obj2;

       obj1.count = 5;
       cout << obj2.count; // Output: 5
       return 0;
     }

