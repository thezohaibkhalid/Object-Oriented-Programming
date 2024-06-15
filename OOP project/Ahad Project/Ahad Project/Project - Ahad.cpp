#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include <vector>

using namespace std;
void login_as();
void login_user();
void header();
void registeration();
void login();
void admin_login();
void user_display();

class Student{
	protected :
		int rollno, age;
		string name;
	public:
	    Student (int stdRollno, string stdName, int stdAge){
	    	rollno=stdRollno;
	    	name=stdName;
	    	age=stdAge;
		}	
		void setRollno(int stdRollno){
			rollno= stdRollno;
		}
		int getRollno(){
			return rollno;
		}
		
		void setName(string stdName){
			name=stdName;
		}
		string getName(){
			return name;
		}
		
		void setAge(int stdAge){
			age= stdAge;
		}
		int getAge(){
			return age;
		}
		
		void displayStudent(){
			cout <<"Roll no: " <<rollno <<endl;
			cout<<"Name: " << name<< endl;
			cout <<"Age: " <<age<<endl;
		}
};

//function to update data of Student
void updateStudent(vector<Student> &students){
	string sname;
	int choice;
	bool found=false;
	
	cout <<"\t\tEnter Name to Update Record: ";
	cin.ignore();
	getline(cin,sname);
	
	for(int i=0; i<students.size(); i++){
		if (students[i].getName()==sname){
			found=true;
			
			cout << "\t\t------Student Found------"<<endl;
			cout<<"\t\t 1.Update Student Roll No: " << endl;
			cout<<"\t\t 2.Update Student Name: " << endl;
			cout<<"\t\t 3.Update Student Age: " << endl;
			cout<<"\t\tEnter your choice: ";
			cin>>choice;
			
			switch(choice){
				case 1: {
					int rno;
					cout <<"\t\t Enter new Roll no: ";
					cin>>rno;
					students[i].setRollno(rno);
					break;
				}
				case 2: {
					string name;
					cout <<"\t\t Enter New Name: ";
					cin.ignore();
					getline(cin,name);
					students[i].setName(name);
					break;
				}
				case 3: {
					int age;
					cout <<"\t\t Enter New Age number: ";
					cin>>age;
					students[i].setAge(age);
					break;
				}
				
				default:
					cout <<"\t\t Invalid Number....."<<endl;
				
			}
		}
		if(!found){
			cout<<"\t\tRecord Not Found" <<endl;
			return;
		}
	
	}
}

//Function to search a student
void SearchStudent(vector<Student> &students){
	int rollno;
	cout<<"\t\tEnter Roll No: ";
	cin>>rollno;
	
	for(int i=0; i<students.size(); i++){
		if(students[i].getRollno()==rollno){
			cout <<"\t\t----------Student Found-----------"<<endl;
			students[i].displayStudent();
			return;
		}
	}

}

//Function to display all students
void DisplayAllStudent(vector<Student> &students){
	if (students.empty()){
		cout <<"\t\tno Student Found"<<endl;
		return;
	}
	for(int i=0; i<students.size(); i++){
		students[i].displayStudent();
		cout<<endl;
		
	}
}



//Created a Function to Add New Students
void addNewStudent(vector<Student> &students){
	int rollno, age;
	string name;
	cout <<"Enter Roll Number: ";
	cin >> rollno;
	
	// Check if student already exist
	for(int i=0; i<students.size(); i++){
		if(students[i].getRollno()==rollno){
			cout<< "\t\tStudent Already Exist...";
			return;
		}
	}
	
	cout <<"Enter Name: ";
	cin >> name;
	cout << "Enter Age: ";
	cin >> age;
	
	Student newStudent(rollno, name,age);
	students.push_back(newStudent);
	
	cout <<"\t\tStudent Added Succesully...."<<endl;
}

//Function to delete Student from the data
void deleteStudent(vector<Student> &students){
	string name;
	cout<<"Enter Name to Delete: ";
	cin.ignore();
	cin>>name;
	
	for(int i=0; i<students.size(); i++){
		if(students[i].getName()==name){
			students.erase((students.begin()+i));
			cout<<"\t\tStudent Removed Successfully" <<endl;
			
		}
	}
}
	vector<Student> students;
	
	
void selection_option() {
    students.push_back(Student(99, "Mahad", 19));

    string choice;
    do {
        system("cls");
        header();

        // Menu Options
        cout << "\t\t---------------------------------" << endl;
        cout << "\t\tStudent Management System" << endl;
        cout << "\t\t---------------------------------" << endl;
        cout << "\t\t 1. Add New Student" << endl;
        cout << "\t\t 2. Display All Students" << endl;
        cout << "\t\t 3. Search Student" << endl;
        cout << "\t\t 4. Update Student" << endl;
        cout << "\t\t 5. Delete Student" << endl;
        cout << "\t\t 6. LogOut" << endl;
        cout << "\t\tEnter your Choice: ";

        int op;
        cin >> op;

        switch (op) {
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                login_as();
            default:
                cout << "\t\tInvalid Number Entered...." << endl;
        }

        cout << "\t\tDo you want to Continue [Yes / No] ? : ";
        cin >> choice;
    } while (choice == "yes" || choice == "Yes" || choice == "y");
}



void header(){
	cout<<"==========================================================================================\n";
	cout<<"                STUDENT        RECORD       MANAGEMENT       SYSTEM                       \n";
	cout<<"==========================================================================================\n";                            
}

int main() {
    cout << "\033[32;40m";

    loginAs();

    return 0;
}

void registration() {
    system("CLS");
    Header();

    std::string username, checkName, password;
    bool isDuplicate;

    std::ifstream checkNameFile("username.txt");

    do {
        std::cout << "Enter a username: ";
        std::cin >> username;
        isDuplicate = false;

        checkNameFile.clear();
        checkNameFile.seekg(0, std::ios::beg);

        while (!checkNameFile.eof()) {
            std::getline(checkNameFile, checkName);
            if (checkName == username) {
                isDuplicate = true;
                std::cout << "This username is already taken." << std::endl;
                Sleep(1000);
                system("CLS");
                displayHeader();
                break;
            }
        }
    } while (isDuplicate);

    checkNameFile.close();

    std::ofstream saveNameFile("username.txt", std::ios::app);
    saveNameFile << username << std::endl;
    saveNameFile.close();

    system("CLS");
    displayHeader();

    std::cout << "Create a password: ";
    std::cin >> password;

    std::ofstream savePasswordFile("password.txt", std::ios::app);
    savePasswordFile << password << std::endl;
    savePasswordFile.close();
}


void login() {
    string name, pass, checkname, checkpass;
    bool samename, samepass;

    ifstream check_name("username.txt");
    ifstream check_pass("password.txt");

    do {
        system("CLS");
        header();
        cout << "Enter a username: ";
        cin >> name;
        samename = false;

        check_name.clear();
        check_name.seekg(0, ios::beg);

        while (getline(check_name, checkname)) {
            if (checkname == name) {
                samename = true;
                break;
            }
        }

        if (!samename) {
            cout << "Wrong Username.";
            Sleep(1000);
        }
    } while (!samename);

    check_name.close();

    do {
        cout << "Enter a password: ";
        cin >> pass;
        samepass = false;

        check_pass.clear();
        check_pass.seekg(0, ios::beg);

        while (getline(check_pass, checkpass)) {
            if (checkpass == pass) {
                samepass = true;
                break;
            }
        }

        if (!samepass) {
            cout << "Wrong password";
            Sleep(1000);
            system("CLS");
        }
    } while (!samepass);

    check_pass.close();
}


void login_user() {
    int choice;
    bool exitRequested = false;

    while (!exitRequested) {
        system("CLS");
        header();
        cout << "1. Registration" << endl
             << "2. Login" << endl
             << "3. Exit" << endl;

        cout << "Enter your choice: ";
        choice = getch();

        switch (choice) {
            case 49: // ASCII code for '1'
                registration();
                exitRequested = true;
                break;
            case 50: // ASCII code for '2'
                login();
                exitRequested = true;
                break;
            case 51: // ASCII code for '3'
                exitRequested = true;
                exit(0);
                break;
            default:
                break;
        }
    }
}

void admin_login() {
    string name, pass;

    do {
        system("CLS");
        header();
        cout << "Enter a username: ";
        cin >> name;

        if (name != "zohaib") {
            cout << "Wrong Username";
            Sleep(1000);
        }
    } while (name != "zohaib");

    do {
        system("CLS");
        header();
        cout << "Enter a password: ";
        cin >> pass;

        if (pass != "imtheleader") {
            cout << "Wrong Password";
            Sleep(1000);
        }
    } while (pass != "imtheleader");

    selection_option();
}

void login_as(){
	int ch,a=0;
	system("CLS");
	header();
	while(a<1){
	cout<<"1. Admin"<<endl
		<<"2. Student"<<endl
		<<"3. Exit";	
	switch(ch=getch()){
		case 49:
			admin_login();
			break;
		case 50:
			login_user();
			DisplayAllStudent(students);
			getch();
			break;
		case 51:
			exit(0);
			
		}
	}
	
}
