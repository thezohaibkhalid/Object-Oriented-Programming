#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr;

    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->makeSound();  // Calls the makeSound() of Dog class

    animalPtr = &cat;
    animalPtr->makeSound();  // Calls the makeSound() of Cat class

    return 0;
}

