


//----------------------------------------------------------------------------------------Example no 18.13--->
//Write a program that stores an object to a file country.txt using binary I/O.

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

  void toFile(const char* filename) {
    ofstream out(filename, ios::binary);
    out.write((char*)&id, sizeof(id));
    out.write(name, sizeof(name));
    out.close();
  }

  void fromFile(const char* filename) {
    ifstream in(filename, ios::binary);
    in.read((char*)&id, sizeof(id));
    in.read(name, sizeof(name));
    in.close();
  }
};

void main() {
  Country cn;
  ofstream out("c:\\country.txt", ios::binary);
  cn.get();
  out.write((char*)&cn, sizeof(cn));
  out.close;

  return 0;
}
