#include<iostream>
using namespace std;
class employee{
	private:
		string name;
		int salary;
		int age;
	public:
	void get_info(){
		
		cout<<"Enter Your name : ";
		getline(cin,name);
		cin.ignore();
		cout<<"Enter Your salery : ";
		cin>>salary;
	    cout<<"Enter your age : ";
		cin>>age;
	}
	void display(){
		cout<<" The name of the Employee is :"<<name<<endl;
		cout<<"The age of the Employee is : "<<age<<endl;
		cout<<"The salery of the Employee is : "<<salary<<endl;
	}
};

int main()
{
	employee obj;
	obj.get_info();
	obj.display();
	return 0;
}
