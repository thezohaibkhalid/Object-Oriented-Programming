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

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    dog.sound(); // Output: Dog barks.
    cat.sound(); // Output: Cat meows.
    return 0;
}
