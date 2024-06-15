#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Mammal : public Animal {
};

class Dog : public Mammal {
public:
    void sound() {
        cout << "Dog barks." << endl;
    }
};

class Bird {
public:
    void sound() {
        cout << "Bird chirps." << endl;
    }
};

class Parrot : public Dog, public Bird {
public:
    void sound() {
        Dog::sound();
        Bird::sound();
    }
};

int main() {
    Parrot parrot;
    parrot.sound();
    return 0;
}
