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

    void setOccupation(string o) {
        occupation = o;
    }

    bool canCook() {
        if (canCook1 == 'y' || canCook1 == 'Y'){
        	return true;
		}else{
			return false;
		}
    }

    void setCanCook(char c) {
        canCook1 = c;
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
    Person person2("Zohaib", 18, 'm', "Engineer", 'n');
    cout << "Person 2:\n"
         << "Name: " << person2.getName() << "\n"
         << "Age: " << person2.getAge() << "\n"
         << "Gender (Male): " << person2.isMale() << "\n"
         << "Occupation: " << person2.getOccupation() << "\n"
         << "Can Cook: " << person2.canCook() << "\n\n";

    // Copy constructor
    Person person3 = person2;
    person3.setName("Unknown");
    person3.setAge(18);
    person3.isFemale();
    person3.setOccupation("Engineer");
    person3.setCanCook('y');
    cout << "Person 3:\n"
         << "Name: " << person3.getName() << "\n"
         << "Age: " << person3.getAge() << "\n"
         << "Gender (Female): " << person3.isFemale() << "\n"
         << "Occupation: " << person3.getOccupation() << "\n"
         << "Can Cook: " << person3.canCook() << "\n\n";

    return 0;
}

