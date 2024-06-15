#include<iostream>
using namespace std;

class A{
public:
	void fun(){
	cout<<"This is base class !! ";
    }
};

class B:public A{
public:
	void fun(){
	cout<<"This is Derived class !! ";
}
};

int main(){
/*	A *ptr;
	B obj;
	ptr=&obj;
	ptr->fun();
	return 0;*/
	
	B obj;
	obj.A::fun();
	return 0;
}