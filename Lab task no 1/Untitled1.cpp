#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;
    string occupation;
    char canCook1;

public:
    // Default constructor
    Person() {
        name = "";
        age = 0;
        gender = 'm';
        occupation = "student";
        canCook1 = 'n';
    }

    // Parameterized constructor
    Person(string n, int a, char g, string o, char c) {
        name = n;
        age = a;
        gender = g;
        occupation = o;
        canCook1 = c;
    }

    // Copy constructor
    Person(const Person& other) {
        name = other.name;
        age = other.age;
        gender = other.gender;
        occupation = other.occupation;
        canCook1 = other.canCook1;
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

    string getOccupation() {
        return occupation;
    }

    bool canCook() {
        return (canCook1 == 'y' || canCook1 == 'Y');
    }
};

int main() {
    // Create objects using different constructors
    Person person1;  // Default constructor
    Person person2("zohaib", 18, 'm', "student", 'y');  // Parameterized constructor
    Person person3 = person2;  // Copy constructor

    // Access methods and display results
    cout << "Person 1: Name: " << person1.getName() << ", Age: " << person1.getAge() << ", Male: " << (person1.isMale() ? "Yes" : "No") << ", Can Cook: " << (person1.canCook() ? "Yes" : "No") << endl;
    cout << "Person 2: Name: " << person2.getName() << ", Age: " << person2.getAge() << ", Male: " << (person2.isMale() ? "Yes" : "No") << ", Can Cook: " << (person2.canCook() ? "Yes" : "No") << endl;
    cout << "Person 3: Name: " << person3.getName() << ", Age: " << person3.getAge() << ", Male: " << (person3.isMale() ? "Yes" : "No") << ", Can Cook: " << (person3.canCook() ? "Yes" : "No") << endl;

    // Modify attributes using setter methods
    person1.setName("Zohaib");
    person1.setAge(18);

    // Display modified attributes
    cout << "Person 1 (modified): Name: " << person1.getName() << ", Age: " << person1.getAge() << ", Male: " << (person1.isMale() ? "Yes" : "No") << ", Can Cook: " << (person1.canCook() ? "Yes" : "No") << endl;

    return 0;
}

