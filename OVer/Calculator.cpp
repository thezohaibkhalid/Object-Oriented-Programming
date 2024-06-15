#include<iostream>
using namespace std;

class Calculator{
private:
	int a,b;
public:
    Calculator{
		cout<<"Please select a Number b/w 1-4 ";
		cout<<"Select 1 to add ";
		cout<<"Select 2 to substract ";
		cout<<"Select 3 to divide ";
		cout<<"Select 4 to multiply"
		cout<<"Select 0 to exit ";
	}
	
int main(){
	cout<<"Enter the Number ";
	cin>>>choice;

	int choice;
	swich(choice){
		case '1'{
			cout<<"The Addition of a and b is equal to ";<<a+b<<endl;
			break;
		}
		case '2'{
			cout<<"The substraction of A and B is equal to "<<a-b<<endl;
	}
}