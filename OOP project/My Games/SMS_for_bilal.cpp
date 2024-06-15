#include<iostream>
using namespace std;
class Student
{
	public:
    	string roll_no[30],name[30],Class[30],course[30],mobile_no[30],admission_year[30];
    	int total = 0;
    	void Enter()
        {
            int ch = 0;
            cout << "How many students do u want to enter??"<<endl;
            cin  >> ch;
            if(total == 0)
            {
                total = ch + total;
                for(int i = 0 ; i < ch ; i++)
                {
                    cout << "\nEnter the Data of student "<<i+1<<endl<<endl;
                    cout << "Enter Roll NO:: "<<endl;
                    cin  >> roll_no[i];
                    cout << "Enter Name: "<<endl;
                    cin  >> name[i];
                    cout << "Enter Class: "<<endl;
                    cin  >> Class[i];
                    cout << "Enter Course: "<<endl;
                    cin  >> course[i];
                    cout << "Enter Mobile NO: "<<endl;
                    cin  >> mobile_no[i];
                    cout << "Enter Admission Year: "<<endl;
                    cin  >> admission_year[i];
                }
            }
            else
            {
                for(int i = total ; i < ch + total ; i++)
                //to store onward students data rather than storing double data()
                {
                    cout << "\nEnter the Data of student "<<i+1<<endl;
                    cout << "Enter Roll NO ";
                    cin  >> roll_no[i];
                    cout << "Enter Name: ";
                    cin  >> name[i];
                    cout << "Enter Class: ";
                    cin  >> Class[i];
                    cout << "Enter Course: ";
                    cin  >> course[i];
                    cout << "Enter Mobile NO: ";
                    cin  >> mobile_no[i];
                    cout << "Enter Admission Year: ";
                    cin  >> admission_year[i];
                }
                total = ch + total; //making choice
            }
        }
        void Show()
        {
            if(total == 0)
            {
                cout << "No Data is Entered" << endl;
            }
            else
            {
                for(int i = 0 ; i < total ; i++)
                {
                    cout << "\nData of Student "<< i+1 << endl;
                    cout << "Roll NO " << roll_no[i] << endl;
                    cout << "Name " << name[i] << endl;
                    cout << "Class " << Class[i] << endl;
                    cout << "Course " <<course[i] << endl;
                    cout << "Mobile NO " << mobile_no[i] << endl;
                    cout << "Admission Year " << admission_year[i] << endl;
                }
            }
        }
        void Search()
        {
            if(total == 0)
            {
                cout << "No data is Entered"<<endl;
            }
            else
            {
                string rollno;
                cout << "Enter the Roll No of Student" << endl;
                cin  >> rollno;
                for(int i = 0 ; i < total ; i++)
                {
                    if(rollno == roll_no[i])
                    {
                        cout << "Roll NO " << roll_no[i] << endl;
                        cout << "Name " << name[i] << endl;
                        cout << "Class " << Class[i] << endl;
                        cout << "Course " << course[i] << endl;
                        cout << "Mobile NO " << mobile_no[i] << endl;
                        cout << "Admission Year " <<admission_year[i] << endl;
                    }
                }
            }
        }
        void Modify()
        {
            if(total == 0)
            {
                cout << "No Data is Entered"<<endl;
            }
            else
	        {
                string rollno;
                cout << "Enter the Roll No of Student which you want to Update"<<endl;
                cin  >> rollno;
                for(int i = 0 ; i < total ; i++)
                {
                    if(rollno == roll_no[i])
                    {
                        cout << "\nPrevious data" << endl;
                        cout << "Data of Student " << i+1 <<endl;
                        cout << "Roll NO: " << roll_no[i] << endl;
                        cout << "Name " << name[i] << endl;
                        cout << "Class " << Class[i] << endl;
                        cout << "Course " << course[i] << endl;
                        cout << "Mobile NO " << mobile_no[i] << endl;
                        cout << "Admission Year " << admission_year[i] << endl;
                        cout << "\nEnter new data" << endl;
                        cout << "Enter Roll NO ";
                        cin  >> roll_no[i];
                        cout << "Enter Name: ";
                        cin  >> name[i];
                        cout << "Enter Class: ";
                        cin  >> Class[i];
                        cout << "Enter Course: ";
                        cin  >> course[i];
                        cout << "Enter Mobile NO: ";
                        cin  >> mobile_no[i];
                        cout << "Enter Admission Year: ";
                        cin  >> admission_year[i];
                    }
                }
            }
        }
        void Delete()
        {
            if(total == 0)
            {
                cout << "No data is Entered Yet"<<endl;
            }
            else
            {
                int a;
                cout << "Are you Sure to Delete Data?"<<endl;
                cout << "Press 1 to Delete All Record"<<endl;
                cin  >> a;
                if(a == 1)
                {
                    total = 0;
                    cout << "All Record is Deleted..!!"<<endl;
                }
                else
                {
                    cout << "Please Press 1 to Delete All Record"<<endl;
                }
            }
        }
};
int main()
{
	system("COLOR 0C");	
	cout<<"***************************************************************************\n";
	cout<<"                                  Welcome\n";
	cout<<"                                     To\n";
	cout<<"                                Student Record\n";
	cout<<"                              Management System\n";
	cout<<"***************************************************************************\n";
	Student s1;
	cout << "What action do you want to perform?\nChoose here:";
	cout << "\nEnter your Choice:\n";
   int value;
	while(true) //always in Loop
    {
        cout << "\n1.Enter a Student Record.";
	    cout << "\n2.Show a Student Record.";
	    cout << "\n3.Search a Student Record.";
	    cout << "\n4.Modify a Student Record.";
	    cout << "\n5.Delete all Records.";
	    cout << "\n6.Exit the Program"<<endl;
        cin>>value;
        switch(value)
        {
            case 1:
            s1.Enter();
            break;
            case 2:
            s1.Show();
            break;
            case 3:
            s1.Search();
            break;
            case 4:
            s1.Modify();
            break;
            case 5:
            s1.Delete();
            break;
            case 6:
            exit(0);
            break;
            default:
            cout<<"Invalid input"<<endl;
            break;
        }
    }
    return 0;
}
