//----------------------------------------------------------------------------------------Example no 18.14--->
//Write a program that reads the contents of country.txt and display on the screen.

#include <iostream>
#include <fstream>

using namespace std;

class Country {
private:
  int id;
  char name[50];

public:
  void get() {
    cout << "Enter country id: ";
    cin >> id;
    cout << "Enter country name: ";
    cin >> name;
  }

  void show() {
    cout << "Country ID: " << id << endl;
    cout << "Country Name: " << name << endl;
  }
};

int main() {
  Country cn;
  ifstream in("c:\\country.txt", ios::binary);
  if (in.is_open()) {
    in.read((char*)&cn, sizeof(cn));
    cn.show();
    in.close();
  } else {
    cout << "File not found!" << endl;
  }

  return 0;
}

