#include <iostream>
#include <cstdlib> // For using cin.get()
using namespace std;

class geometry //class declared
{
private:
    float length, width;

public:
    //constructor
    geometry(float l, float w)
    {
        length = l;
        width = w;
    }
    void square() //square function declared
    {
        float area, perimeter;
        area = length * width;
        perimeter = 2 * (length) + 2 * (width);
        cout << "area of a [ SQUARE ] is : " << area << endl;
        cout << "perimeter of a [ SQUARE ] is : " << perimeter << endl;
    }
    void rectangle() //rectangle function declared
    {
        float area, perimeter;
        area = length * width;
        perimeter = 2 * (length + width);
        cout << "area of a [ RECTANGLE ] is : " << area << endl;
        cout << "perimeter of a [ RECTANGLE ] is : " << perimeter << endl;
    }
};

int main()
{
again: //for again calling values
    float length, width;
    cout << " enter the length : ";
    cin >> length;
    cout << " enter the width : ";
    cin >> width;
    //constructor
    geometry gum(length, width);
    if (length == width) //condition
    {
        cout << "_____________\n" << endl;
        cout << "the values are equal, so it is [ SQUARE ]" << endl;
        gum.square();
    }
    else
    {
        cout << "_____________\n" << endl;
        cout << "the values are not equal, so it is [ RECTANGLE ]" << endl;
        gum.rectangle();
    }
    cout << "_____________\n" << endl;
    goto again; //goto statement for calling a line.
    cin.get();  // Pause the program before exiting
    return 0;
}
