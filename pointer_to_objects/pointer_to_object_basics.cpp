#include <iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:

    void set_data(int a, int b){
        real = a;
        imaginary = b;
    }
    void get_data(){
        cout << "The value of imaginary number is " << real << endl;
        cout << "The value of imaginary number is " << imaginary << endl;
    }


};

int main()
{
    // Complex c1;
    // // c1.set_data(12,15);
    // // c1.get_data();
    // Complex *ptr = &c1;

    // (*ptr).set_data(1,20);
    // (*ptr).get_data();

    //-------------------------->>>Making object by allocating memory to it dynamically using new

    Complex *ptr = new Complex;
    // (*ptr).set_data(1,20);
    // (*ptr).get_data();

    // ------------------------>>> By using arrow operator.
    
    ptr->set_data(3,50); //Arrow means derefrence this pointer both ptr-> and (*ptr) are same
    ptr->get_data();

    //Array of objects
    Complex *ptr1 = new Complex[3];
    ptr1->set_data(4,50); //Arrow means derefrence this pointer both ptr-> and (*ptr) are same
    ptr1->get_data();

    // ptr1+1->set_data(5,50); //Arrow means derefrence this pointer both ptr-> and (*ptr) are same
    // ptr1+1->get_data();  //ptr1 +1 means it is going to the 2nd object we made in array

    return 0;
}