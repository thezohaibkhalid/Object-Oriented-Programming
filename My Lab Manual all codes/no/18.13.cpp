#include <iostream>
#include <fstream>
using namespace std;
class country
{
	private:
		int id;
		char name[50];
	public:
		void get()
		{
			cout<<"Enter country  id: ";
			cin>>id;
			cout<<"Enter country name: ";
			cin>>name;
		}
		
		void show()
		{
			cout<<"Country Id: "<<id<<endl;
			cout<<"Country Name: "<<name<<endl;
		}
};
int main()
{
	country cn;
	ofstream out("country.txt, ios::binary");
	cn.get();
	out.write((char*)&cn, sizeof(cn));
	out.close();
}