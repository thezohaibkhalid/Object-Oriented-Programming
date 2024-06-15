#include <iostream>
using namespace std;

int main()
{
    // Declare and initialize pointers
    // int* p_age {};     // This initializes p_age with a null pointer
    // double* p_name {}; // This also initializes p_name with a null pointer

    // Explicitly initialize with nullptr (you can use either this or the above syntax, not both)
    int* p_age {nullptr};
    double* p_name {nullptr};
    
    //Pointers of differient variables are of the same size.
    cout << "Size of int " << sizeof(int) << endl;
    cout << "Size of int* " << sizeof(int*) << endl;
    cout << "Size of double " << sizeof(double) << endl;
    cout << "Size of double* " << sizeof(double*) << endl;
    cout << "Size of p_age " << sizeof(p_age) << endl;
    cout << "Size of p_name " << sizeof(p_name) << endl;

    //initializing pointers and assigning them data
    int p_age1 {10}; //similar to int p_age1 = 10
    int *ptr {&p_age1};

    cout << "p_age1 is equal to " << p_age1 << endl;
    cout << "The adress of p_age1 in memory is " << ptr;
    return 0;
}
