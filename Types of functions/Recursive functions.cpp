#include<iostream>
using namespace std;

int fact(int n){
	if(n==0){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

int main()
{
	int n;
	cout<<"Enter the number you want to calculate the factorial of : ";
	cin>>n;
	cout<<fact(n);
	return 0;
}
