#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;
    string occupation;
    char canCook;

public:
    // Default constructor
    Person() {
        name = "";
        age = 0;
        gender = 'm';
        occupation = "student";
        canCook = 'n';
    }

    // Parameterized constructor
    Person(string n, int a, char g, string o, char c) {
        name = n;
        age = a;
        gender = g;
        occupation = o;
        canCook = c;
    }

    // Copy constructor
    Person(const Person& other) {
        name = other.name;
        age = other.age;
        gender = other.gender;
        occupation = other.occupation;
        canCook = other.canCook;
    }

    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    int getAge() {
        return age;
    }

    void setAge(int a) {
        age = a;
    }

    bool isMale() {
        return gender == 'm';
    }

    bool isFemale() {
        return gender == 'f';
    }

    bool canCook() {
        return canCook == 'y';
    }
};

int main() {
    // Create objects using different constructors
    Person person1;  // Default constructor
    Person person2("John", 25, 'm', "engineer", 'y');  // Parameterized constructor
    Person person3 = person2;  // Copy constructor

    // Access methods and display results
    cout << "Person 1: " << person1.getName() << ", " << person1.getAge() << ", Male: " << boolalpha << person1.isMale() << ", Can cook: " << boolalpha << person1.canCook() << endl;
    cout << "Person 2: " << person2.getName() << ", " << person2.getAge() << ", Male: " << boolalpha << person2.isMale() << ", Can cook: " << boolalpha << person2.canCook() << endl;
    cout << "Person 3: " << person3.getName() << ", " << person3.getAge() << ", Male: " << boolalpha << person3.isMale() << ", Can cook: " << boolalpha << person3.canCook() << endl;

    // Modify attributes using setter methods
    person1.setName("Alice");
    person1.setAge(30);

    // Display modified attributes
    cout << "Person 1 (modified): " << person1.getName() << ", " << person1.getAge() << ", Male: " << boolalpha << person1.isMale() << ", Can cook: " << boolalpha << person1.canCook() << endl;

    return 0;
}

