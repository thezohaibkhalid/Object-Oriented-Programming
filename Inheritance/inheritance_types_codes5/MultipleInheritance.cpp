#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Bird {
public:
    void sound() {
        cout << "Bird chirps." << endl;
    }
};

class Parrot : public Animal, public Bird {
public:
    void sound() {
        cout << "Parrot imitates both Animal and Bird sounds." << endl;
    }
};

int main() {
    Parrot parrot;
    parrot.sound(); // Output: Parrot imitates both Animal and Bird sounds.
    return 0;
}
