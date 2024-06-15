// #include<iostream>
// using namespace std;

// class Base{
// public:	
// 	void fun(){
// 		cout<<"This is a base class!!! ";
// 	}
// };

// class Derived: public Base{
// public:
// 	void fun(){
// 		cout<<"This  Derived class!!! ";
// 	}
// };

// int main(){
// 	Derived obj;
// 	obj.fun();
// 	obj.Base::fun();
// 	return 0;
// }


#include<iostream>
using namespace std;

class Base {
public:
    virtual void fun() {
        cout << "This is a base class!!! ";
    }
};

class Derived : public Base {
public:
    void fun() override {
        cout << "This is a Derived class!!! ";
    }

    void callBaseFun() {
        Base::fun(); // Calling the base class function
    }
};

int main() {
    Derived obj;
    obj.fun(); // Calls the overridden function in the Derived class
    obj.callBaseFun(); // Calls the function in the base class using the derived class instance
    return 0;
}
