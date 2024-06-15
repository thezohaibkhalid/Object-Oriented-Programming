/*we have defined a base class Animal with a public member function sound() 
that outputs 'Animal makes a sound.' We have also created a derived class Dog,
 which publicly inherits from the Animal class. The Dog class overrides the sound() 
function and provides its own implementation to output 'Dog barks.' In the main()
function, we create an object dog of the Dog class and call the sound() member function
 on the dog object. As a result, the output will be 'Dog barks.' due to the function override
  in the Dog class."*/
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Dog barks." << endl;
    }
};

int main() {
    Dog dog;
    dog.sound(); // Output: Dog barks.
    return 0;
}
