#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
using namespace std;

class Library{
	int BookId;
	char Title[20];
	char Author[20];
	char Category[20];
	int Pages;
	float Eddition;
	public:
	int getID(){
		return BookId;
	}
	char* getTitle(){return Title;}
	char* getAuthor(){return Author;}
	char* getCategory(){return Category;}
	float getEddition(){return Eddition;}

    Library(){
    	BookId=0;
    	strcpy(Title, "");
    	strcpy(Author, "");
    	strcpy(Category, "");
    	Pages=0;
    	Eddition=0;
	}
	
	void getBook();
	void listView();
	void showBook();
	void header();
}l;

void Library::getBook(){
	cout<<"\tEnter Book Id: ";
	cin>>BookId;
	cout<<"\tEnter Book Title: ";
	cin.get();
	cin.getline(Title, 20);
	cout<<"\tEnter Book Author: ";
	cin.getline(Author, 20);
	cout<<"\tEnter Book Category: ";
	cin.getline(Category, 20);
	cout<<"\tEnter No. of Pages: ";
	cin>>Pages;
	cout<<"\tEnter Eddition of Book: ";
	cin>>Eddition;
	cout<<endl;
}

void Library::showBook()
{
    cout<<endl;
    cout<<"Book ID        : "<<BookId<<endl;
    cout<<"Book Title     : "<<Title<<endl;
    cout<<"Author Name    : "<<Author<<endl;
    cout<<"Category       : "<<Category<<endl;
    cout<<"No. of Pages   : "<<Pages<<endl;
    cout<<"Eddition       : "<<Eddition<<endl;
}

void Library::header()
{
	cout.setf(ios::left);
	cout<<setw(5)<<"I.D."
	<<setw(20)<<"Book Title"
	<<setw(20)<<"Book Author"
	<<setw(15)<<"Category"
	<<setw(6)<<"Pages"
	<<setw(6)<<"Eddition"<<endl;
	for(int i=1; i<=72; i++){
		cout<<"=";
	}
	cout<<endl;
}

void Library::listView()
{
	cout.setf(ios::left);
	cout<<setw(5)<<BookId
	<<setw(20)<<Title
	<<setw(20)<<Author
	<<setw(15)<<Category
	<<setw(6)<<Pages
	<<setw(6)<<Eddition<<endl;
}

void drawline(char);
void heading();
void searchMenu();
void addBook();
void displayBooks();

void searchByID();
void searchByTitle();
void searchByCategory();
void searchByEddition();
void searchByAuthor();

void dispose();
void modify();
void displayDisposed();
void issueBook();
void dispayIssued();

void selectMenu();

void drawLine(char ch)
{
	for(int i=1; i<80; i++){
		cout<<ch;
	}
	cout<<endl;
}

void heading()
{
	drawLine('+');
	cout<<"\t\tL I B R A R Y    M A N A G E M E N T    S Y S T E M\n";
	drawLine('+');
}

void addBook()
{
	ofstream fout;
	fout.open("books.dat", ios::app);
	l.getBook();
	fout.write((char*)&l, sizeof(l));
	cout<<"Book data saved in file.....\n";
	fout.close();
}

void displayBooks()
{
	ifstream fin("books.dat");
	int rec=0;
	while(fin.read((char*)&l, sizeof(l)))
	{
	if(rec<1){
	l.header();		
	}
	l.listView();
	rec++;
	}
	fin.close();
	cout<<"\nTotal "<<rec<<" Records in file...\n";
}

void searchByID()
{
	int n, flag=0;
	ifstream fin("books.dat");
	cout<<"Enter Book ID : ";
	cin>>n;
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(n==l.getID())
		{
	l		;l.showBook();
			flag++;
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book Number with ID: "<<n<<" not available...\n";
	}
}

void searchByEddition()
{
	int n, flag=0;
	ifstream fin("books.dat");
	cout<<"Enter Book Eddition : ";
	cin>>n;
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(n==l.getEddition())
		{
	l		;l.showBook();
			flag++;
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book Number with Eddition: "<<n<<" not available...\n";
	}
}

void searchByTitle()
{
	int flag=0;
	char title[20];
	ifstream fin("books.dat");
	cout<<"Enter Book Title : ";
	cin.ignore();
	cin.getline(title, 20);
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(strcmpi(title, l.getTitle())==0)
		{
		l.showBook();
		flag++;
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book with Title: "<<title<<" not avaiable...\n";
	}
}

void searchByCategory()
{
	int flag=0, rec=0;
	char cat[20];
	ifstream fin("books.dat");
	cout<<"Enter Book Category : ";
	cin.get();
	cin.getline(cat, 20);
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(strcmpi(cat, l.getCategory())==0)
		{
			if(rec<1){
				l.header();
			}
		l.listView();
		flag++;
		rec++;
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book with Category: "<<cat<<" not avaiable...\n";
	}
}

void searchByAuthor()
{
	int flag=0, rec=0;
	char aut[20];
	ifstream fin("books.dat");
	cout<<"Enter Book Author : ";
	cin.ignore();
	cin.getline(aut, 20);
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(strcmpi(aut, l.getAuthor())==0)
		{
			if(rec<1){
				l.header();
			}
		l.listView();
		flag++;
		rec++;
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book with Author name: "<<aut<<" not avaiable...\n";
	}
}

void dispose()
{
    fstream file,temp;	
	int flag=0, n;
	file.open("books.dat", ios :: binary | ios :: in);
	temp.open("temp.dat", ios :: binary | ios :: out);
	ofstream fout("dispose.dat", ios::app);
	cout<<"Enter Book ID : ";
	cin>>n;
	while(file.read((char*)&l, sizeof(l)))
	{
		if(n==l.getID())
		{
			flag++;
			fout.write((char*)&l, sizeof(l));
			continue;
		}
        temp.write((char*)&l, sizeof(l));
	}
	file.close();
	temp.close();
	fout.close();
	remove("books.dat");
	rename("temp.dat", "books.dat");
	if(flag==1){
		cout<<"Record Deleted"<<endl;
	}
	else{
		cout<<"Book Number with ID: "<<n<<" not avaiable...\n";
	}
}

void issueBook()
{
    fstream file,temp;	
	int flag=0, n;
	file.open("books.dat", ios :: binary | ios :: in);
	temp.open("temp.dat", ios :: binary | ios :: out);
	ofstream fout("issued.dat", ios::app);
	cout<<"Enter Book ID : ";
	cin>>n;
	while(file.read((char*)&l, sizeof(l)))
	{
		if(n==l.getID())
		{
			flag++;
			fout.write((char*)&l, sizeof(l));
			continue;
		}
        temp.write((char*)&l, sizeof(l));
	}
	file.close();
	temp.close();
	fout.close();
	remove("books.dat");
	rename("temp.dat", "books.dat");
	if(flag==1){
		cout<<"Book Number with ID: "<<n<<" has been issued...\n"<<endl;
	}
	else{
		cout<<"Book Number with ID: "<<n<<" not avaiable...\n";
	}
}

void displayIssued()
{
	ifstream fin("issued.dat");
	int rec=0;
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(rec<1){
		l.header();
		}
		l.listView();
		rec++;
	}
   fin.close();
   cout<<"\nTotal "<<rec<<" Books that have been Issued...\n";	
}

void modify()
{
	int flag=0, n, pos;
	fstream fin("books.dat", ios::in|ios::out);
	cout<<"Enter Book ID : ";
	cin>>n;
	while(fin.read((char*)&l, sizeof(l)))
	{
		if(n==l.getID())
		{
			pos=fin.tellg();
			cout<<"Following data will be edited...\n";
			l.showBook();
			flag++;
			fin.seekg(pos-sizeof(l));
			l.getBook();
			fin.write((char*)&l, sizeof(l));
			cout<<"\nData Modified successfully...\n";
		}
	}
	fin.close();
	if(flag==0){
		cout<<"Book Number with ID: "<<n<<" not avaiable...\n";
	}
}

void displayDisposed()
{
	ifstream fin("dispose.dat");
	int rec=0;
	while(fin.read((char*)&l, sizeof(l)))
	{
	    if(rec<1){
		l.header();
		}
		l.listView();
		rec++;
	}
   fin.close();
   cout<<"\nTotal "<<rec<<" Records in disposed off file...\n";	
}

void searchMenu()
{
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"BOOK SEARCH OPTIONS\n";
		cout<<"0. Back\n";
		cout<<"1. By ID\n";
		cout<<"2. By Title\n";
		cout<<"3. By Category\n";
		cout<<"4. By Author\n";
		cout<<"5. By Eddition\n";
		cout<<"Enter Your Choice : ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1: system("COLOR DE"); searchByID(); break;
			case 2: system("COLOR 6E"); searchByTitle(); break;
			case 3: system("COLOR DF"); searchByCategory(); break;
			case 4: system("COLOR 6F"); searchByAuthor(); break;
			case 5: system("COLOR 4B"); searchByEddition(); break;
			default: cout<<"\a";
		}
		system("pause");
	}while(ch!=0);
}

class User{
	public:
		virtual void menu()=0;
		virtual void main()=0;
		virtual void login()=0;
		virtual void registeration()=0;
};

class Admin: public User{
	public:
		void menu();
		void main();
		void login();
		void registeration();
}adm;

void Admin :: menu()
{
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"1. Add New Book\n";
		cout<<"2. Display All Books\n";
	 	cout<<"3. Search Books\n";
		cout<<"4. Delete Book Record\n";
		cout<<"5. Modify Details\n";
		cout<<"6. List of Deleted Books\n";
		cout<<"7. List of Issued Books\n";
		cout<<"8. Log Out.\n";
		cout<<"Enter Your Choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1: system("COLOR DE"); addBook(); break;
			case 2: system("COLOR DF"); displayBooks(); break;
			case 3: system("COLOR 6E"); searchMenu(); break;
			case 4: system("COLOR 6F"); dispose(); break;
			case 5: system("COLOR 4E"); modify(); break;
			case 6: system("COLOR 4F"); displayDisposed(); break;
			case 7: system("COLOR 4F"); displayIssued(); break;
			case 8: adm.main(); break;
		}
		system("pause");
	}while(ch!=0);
}

void Admin :: main(){
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"1. Login.\n";
		cout<<"2. Register.\n";
		cout<<"3. Exit.\n";
		cout<<"Enter Your Choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1: system("COLOR 0A"); adm.login(); break;
			case 2: system("COLOR 0A"); adm.registeration(); break;
			case 3: selectMenu(); break;
		}
		system("pause");
	}while(ch!=0);
}

void Admin :: login(){
	int count;
	string userId, password, id, pass;
    system("cls");
    heading();
    cout<<"Enter Your Username and Password\n";
    cout<<"USERNAME: ";
    cin>>userId;
    cout<<"PASSWORD: ";
    cin>>password;
    
    ifstream input("adminrecord.txt");
    
    while(input>>id>>pass)
    {
    	if(id==userId && pass==password)
    	{
    		count=1;
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<endl<<userId<<" Your Login is successfull \nThanks for logging in ! \n";
		Sleep(1000);
        adm.menu();
	}
	else{
		cout<<"\nLogin Error \nPlease check your username and password\n";
		Sleep(1000);
		adm.main();
	}
}

void Admin :: registeration(){
	string ruserId, rpassword, rId, rpass;
	int count=0;
	system("cls");
	heading();
	cout<<"Enter the username : ";
	cin>>ruserId;
	cout<<"Enter the password : ";
	cin>>rpassword;
	ofstream f1("adminrecord.txt", ios::app);
	ifstream input("adminrecord.txt");
    
    while(input>>rId)
    {
	if(rId==ruserId)
    	{
    cout<<"\nUsername already exists...";
	cout<<"\nTry registring with another username";
	Sleep(1000);
	adm.registeration();		
		}
    }
	f1<<ruserId<<' '<<rpassword<<endl;
	
	cout<<"\nRegistration is successfull! \n";
	Sleep(1000);
	system("cls");
	adm.main();
}

class Student: public User{
	public:
		void menu();
		void main();
		void login();
		void registeration();
}st;

void Student :: menu()
{
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"1. Display All Books\n";
		cout<<"2. Search Books\n";
		cout<<"3. Issue Book\n";
		cout<<"4. Log Out\n";
		cout<<"Enter Your Choice: ";
		cin>>ch;
		system("CLS");
		heading();
		switch(ch)
		{ 
			case 1: system("COLOR 4F"); displayBooks(); break;
			case 2: system("COLOR 6E"); searchMenu(); break;
			case 3: system("COLOR 4F"); issueBook(); break;
			case 4: st.main(); break;
		}
		system("pause");
	}while(ch!=0);
}

void Student :: main(){
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"1. Login.\n";
		cout<<"2. Register.\n";
		cout<<"3. Exit.\n";
		cout<<"Enter Your Choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1: system("COLOR 0A"); st.login(); break;
			case 2: system("COLOR 0A"); st.registeration(); break;
			case 3: selectMenu();

		}
		system("pause");
	}while(ch!=0);
}

void Student :: login(){
	int count;
	string userId, password, id, pass;
    system("cls");
    heading();
    cout<<"Enter Your Username and Password\n";
    cout<<"USERNAME: ";
    cin>>userId;
    cout<<"PASSWORD: ";
    cin>>password;
    
    ifstream input("studentrecord.txt");
    
    while(input>>id>>pass)
    {
    	if(id==userId && pass==password)
    	{
    		count=1;
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<endl<<userId<<" Your Login is successfull \nThanks for logging in ! \n";
		Sleep(1000);
        st.menu();
	}
	else{
		cout<<"\nLogin Error \nPlease check your username and password\n";
		Sleep(1000);
		st.main();
	}
}

void Student :: registeration(){
	string ruserId, rpassword, rId, rpass;
	int count=0;
	system("cls");
	heading();
	cout<<"Enter the username : ";
	cin>>ruserId;
	cout<<"Enter the password : ";
	cin>>rpassword;
	ofstream f1("studentrecord.txt", ios::app);
	ifstream input("studentrecord.txt");
    
    while(input>>rId)
    {
	if(rId==ruserId)
    	{
    cout<<"\nUsername already exists...";
	cout<<"\nTry registring with another username";
	Sleep(1000);
	st.registeration();		
		}
    }
	f1<<ruserId<<' '<<rpassword<<endl;
	
	cout<<"\nRegistration is successfull! \n";
	Sleep(1000);
	system("cls");
	st.main();
}


void selectMenu(){
	int ch;
	do
	{
		system("cls");
		heading();
		cout<<"1. Admin.\n";
		cout<<"2. Student.\n";
		cout<<"3. Exit.\n";
		cout<<"Enter Your Choice: ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch)
		{
			case 1: system("COLOR DE"); adm.main(); break;
			case 2: system("COLOR DF"); st.main(); break;
			case 3: exit(0); break;
		}
		system("pause");
	}while(ch!=0);
}

int main()
{
	system("COLOR 70");
	selectMenu();
	return 0;
}
