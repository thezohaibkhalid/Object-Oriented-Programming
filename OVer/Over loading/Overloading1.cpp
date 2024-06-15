#include<iostream>
using namespace std;

void num1(int a, int b){
	cout<<"A + B is Equal to : "<<a+b<<endl;
}

void num1(float x, float y){
	cout<<"The addition of A and B is : "<<x+y<<endl;
};

int main(){
int c,d,e,f;
cout<<"Enter the value of A and B :\n";
cin>>c>>d;
num1(c,d);

cout<<"Enter the value for 2nd function :\n";
cin>>e>>f;
num1(e,f);
}