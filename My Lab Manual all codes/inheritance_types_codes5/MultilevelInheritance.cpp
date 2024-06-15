#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
};

class Labrador : public Dog {
public:
    void sound() {
        cout << "Labrador barks." << endl;
    }
};

int main() {
    Labrador labrador;
    labrador.sound(); // Output: Labrador barks.
    return 0;
}
