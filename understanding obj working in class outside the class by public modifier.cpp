#include<iostream>
using namespace std;

class alpha{
	public:
		int a,b;
	alpha(){
		cout<<"Input the vlaue of A : ";
		cin>>a;
		cout<<"Enter the value of B : ";
		cin>>b;
	}
};

class another{
	public:
	another(){
	alpha obj;
	cout<<"Calling the value from Alpha class : "<<obj.a<<endl;
	}

};


int main(){


alpha a;
	cout<<"A plus B is Equal to "<<a.a+a.b;
another b;
}
