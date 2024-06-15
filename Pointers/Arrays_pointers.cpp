#include <iostream>
using namespace std;

int main()
{
    int arr[]={10,20,30,40};
    // cout<<arr[0]<<endl;
    // cout<<arr[1]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<arr[3]<<endl;

    int* p = arr;
    cout << "The number at index 0 / arr[0] is " << *p;//not runing here but will on online compiler
}  