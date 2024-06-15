#include <iostream>
#include <fstream>
using namespace std;
class Country
{
	private:
		int id;
		char name[50];
		public:
			void get()
			{
				cout<<"Enter country id: ";
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
	Country cn;
	ifstream in("country.txt", ios::binary);
	in.read((char*)&cn, sizeof(cn));
	cn.show();
	in.close();
}