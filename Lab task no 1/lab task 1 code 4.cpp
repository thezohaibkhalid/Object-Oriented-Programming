#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;
    string occupation;
    char canCookFood;

public:
    // Default constructor
    Person() : name(""), age(0), gender('m'), occupation("student"), canCookFood('n') {}

    // Parameterized constructor
    Person(string name, int age, char gender, string occupation, char canCookFood)
        : name(name), age(age), gender(gender), occupation(occupation), canCookFood(canCookFood) {}

    // Copy constructor
    Person(const Person& other)
        : name(other.name), age(other.age), gender(other.gender), occupation(other.occupation), canCookFood(other.canCookFood) {}

    string getName() {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    int getAge() {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
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
        return canCookFood == 'y';
    }
};

int main() {
    // Default constructor
    Person person1;
    cout << "Person 1:\n"
        << "Name: " << person1.getName() << "\n"
        << "Age: " << person1.getAge() << "\n"
        << "Gender (Male): " << person1.isMale() << "\n"
        << "Occupation: " << person1.getOccupation() << "\n"
        << "Can Cook: " << person1.canCook() << "\n\n";

    // Parameterized constructor
    Person person2("John", 25, 'm', "Engineer", 'n');
    cout << "Person 2:\n"
        << "Name: " << person2.getName() << "\n"
        << "Age: " << person2.getAge() << "\n"
        << "Gender (Male): " << person2.isMale() << "\n"
        << "Occupation: " << person2.getOccupation() << "\n"
        << "Can Cook: " << person2.canCook() << "\n\n";

    // Copy constructor
    Person person3 = person2;
    person3.setName("Alice");
    person3.setAge(30);
    person3.getOccupation("Doctor");
    person3.canCookFood = 'y';
    cout << "Person 3:\n"
        << "Name: " << person3.getName() << "\n"
        << "Age: " << person3.getAge() << "\n"
        << "Gender (Female): " << person3.isFemale() << "\n"
        << "Occupation: " << person3.getOccupation() << "\n"
        << "Can Cook: " << person3.canCook() << "\n\n";

    return 0;
}

