#include<iostream>
using namespace std;

class Base{
public:
	void fun(){
		cout<<"This is the base class runing!!! ";
	}
		
};
class Derived: public Base{
/*public:	
	void fun(){
		cout<<"This is the Derived class runing!!!" ;
	}*/
};

int main(){
	
	Derived d;
	d.fun();
	
	return 0;
}