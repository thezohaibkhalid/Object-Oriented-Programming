#include<iostream>
using namespace std;

class Shop{
    private:
    int id;
    float price;
    public:
    setData(int a, float b)
    {
        id = a;
        price = b;
    }
    getData(void)
    {
        cout << " The id of the employee is " << id << endl;
        cout << " The price of the item is " << price << endl;
    }
};

int main()
{
    int size = 3;
    Shop *ptr = new int Shop[size]
    // similar to it,
    // int *ptr = new int [34]; it will dinamically allocate 34 integers in memory
}