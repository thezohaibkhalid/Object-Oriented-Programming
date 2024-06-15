#include <iostream>
using namespace std;
#include <string>

class Person {
private:
    std::string name;
    int age;
    char gender;
    std::string occupation;
    char canCook;

public:
    // Default constructor
    Person() : name(""), age(0), gender('m'), occupation("student"), canCook('n') {}

    // Parameterized constructor
    Person(std::string name, int age, char gender, std::string occupation, char canCook)
        : name(name), age(age), gender(gender), occupation(occupation), canCook(canCook) {}

    // Copy constructor
    Person(const Person& other)
        : name(other.name), age(other.age), gender(other.gender), occupation(other.occupation), canCook(other.canCook) {}

    std::string getName() {
        return name;
    }

    void setName(const std::string& newName) {
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

    std::string getOccupation() {
        return occupation;
    }

    bool canCook() {
        return canCook == 'y';
    }
};
int main() {
    // Default constructor
    Person person1;
    std::cout << "Person 1:\n"
              << "Name: " << person1.getName() << "\n"
              << "Age: " << person1.getAge() << "\n"
              << "Gender (Male): " << person1.isMale() << "\n"
              << "Occupation: " << person1.getOccupation() << "\n"
              << "Can Cook: " << person1.canCook() << "\n\n";

    // Parameterized constructor
    Person person2("John", 25, 'm', "Engineer", 'n');
    std::cout << "Person 2:\n"
              << "Name: " << person2.getName() << "\n"
              << "Age: " << person2.getAge() << "\n"
              << "Gender (Male): " << person2.isMale() << "\n"
              << "Occupation: " << person2.getOccupation() << "\n"
              << "Can Cook: " << person2.canCook() << "\n\n";

    // Copy constructor
    Person person3 = person2;
    person3.setName("Alice");
    person3.setAge(30);
    person3.setOccupation("Doctor");
    person3.canCook = 'y';
    std::cout << "Person 3:\n"
              << "Name: " << person3.getName() << "\n"
              << "Age: " << person3.getAge() << "\n"
              << "Gender (Female): " << person3.isFemale() << "\n"
              << "Occupation: " << person3.getOccupation() << "\n"
              << "Can Cook: " << person3.canCook() << "\n\n";

    return 0;
}


