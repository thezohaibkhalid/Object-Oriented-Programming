// #include<iostream>
// using namespace std;

// typedef struct employee
// {
//     /* data */
//     int eId; //4
//     char favChar; //1
//     float salary; //4
// } ep;

// union money
// {
//     /* data */
//     int rice; //4
//     char car; //1
//     float pounds; //4
// };


// int main(){
//     enum Meal{ breakfast, lunch, dinner};
//     Meal m1 = lunch;
//     cout<<(m1==2);
//     cout<<breakfast;
//     cout<<lunch;
//     cout<<dinner; 
//     union money m1;
//     m1.rice = 34;
//     m1.car = 'c';
//     cout<<m1.car;

//     ep zohaib;
//     struct employee shubham;
//     struct employee rohanDas;
//     zohaib.eId = 1;
//     zohaib.favChar = 'c';
//     zohaib.salary = 120000000;
//     cout<<"The value is "<<zohaib.eId<<endl; 
//     cout<<"The value is "<<zohaib.favChar<<endl; 
//     cout<<"The value is "<<zohaib.salary<<endl; 
//     return 0;
// }

#include <iostream>
using namespace std;

// Define the struct 'employee'
struct employee {
    int eId;
    char favChar;
    int salary;
};

// Define the union 'money'
union money {
    int rice;
    char car;
};

// Define the struct 'ep'
struct ep {
    // Add any required members for the 'ep' struct
};

int main() {
    // Assuming 'breakfast', 'lunch', and 'dinner' are defined elsewhere

    cout << breakfast;
    cout << lunch;
    cout << dinner;

    union money m1;
    m1.rice = 34;
    m1.car = 'c';
    cout << m1.car;

    ep zohaib;
    struct employee shubham;
    struct employee rohanDas;

    zohaib.eId = 1;
    zohaib.favChar = 'c';
    zohaib.salary = 120000000;
    cout << "The value is " << zohaib.eId << endl;
    cout << "The value is " << zohaib.favChar << endl;
    cout << "The value is " << zohaib.salary << endl;

    return 0;
}
