#include <iostream> 
using namespace std;

int main()
{
    int a = 4;

    int* ptr = &a;

    cout<<"The adress of a is equal to " << ptr<<endl;
    cout<<"The value of a is equal to " << *(ptr)<<endl<<endl;

    //New keyword in C++
//--------------------------------------Dynamically initializing
    // int* p = new int (40);
    float *p = new float(40.95);
    cout<<"The adress of new int is equal to " << p<<endl;
    cout<<"The value of new int is equal to " << *(p)<<endl;

//-------------------------------------Dynamically allocating arrays
    int *arr = new int[3];

    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    // delete arr;
    //To free the dynamically allocated array
    delete [] arr;
    cout << "The value of index 1 is ---> "<<arr[0]<<endl;
    cout << "The value of index 2 is ---> "<<arr[1]<<endl;
    cout << "The value of index 3 is ---> "<<arr[2]<<endl;

    // Delete operator


  
    return 0;
}