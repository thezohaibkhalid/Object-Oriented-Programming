
#include <iostream>
using namespace std;

class Employee{//Base class
public:
    int id;
    float salery;
    Employee(){
        id=0;
    }
    Employee(int inpid){
        id = inpid;
        salery = 34.0;
    }

    class Programmer: public Employee{
    public:
        int languagecode=9;
    };
};

int main() {
    Employee zohaib(1), bilal(2);
    cout<<zohaib.salery<<endl;
    cout<<bilal.salery<<endl;
    programmer obj(1)
    return 0;
}
