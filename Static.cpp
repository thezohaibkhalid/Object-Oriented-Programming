#include<iostream>
using namespace std;

                              //static data member   //Static member function
class Employee	
{
	static int count;//without static the count will be zero for every object
	//static variable is shared by all the objects
	int id;
	public: 
	void setdata(void)
	{
		cout<<"Enter the id of Employee number --> ";
		cin>>id;
		count++;
	}
	void getdata(void)
	{
		cout<<"This id of this Employee is "<<id<<" and the Employee number is "<<count<<"."<<endl; 
	}
	static void getcount()
	{
		//cout<<id;//Gives an error that why i am using non static variable in static member function.
		cout<<"The value of count is equal to  "<<count<<endl;
	}


};

int Employee::count;//static variable is default initialized to zero

int main()
{
	Employee Abubakar,Abdullahad,Tabish,Zohaib;
	//obj.id=1;
	//obj.count=1//cannot do this as id and count are private
	Abubakar.setdata();
	Abubakar.getdata();
	Employee::getcount();//accessing the static function of the class

	Abdullahad.setdata();
	Abdullahad.getdata();
	Employee::getcount();
	
	Tabish.setdata();
	Tabish.getdata();
	Employee::getcount();
	
	Zohaib.setdata();
	Zohaib.getdata();
	Employee::getcount();
	
	return 0;
}   

