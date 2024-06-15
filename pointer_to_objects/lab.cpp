#include<iostream>
using namespace std;

// class XYZ{
// public:
//     virtual void print()
//     {
//         cout<<"THis is the parent class ";
//     }
    
// };

// class ABC : public XYZ{
// public:
//     void print ()
//     {
//         cout<<"This is the child class ";
//     }
// };

// int main()
// { //it's an example of dynamic binding or early binding
//     XYZ *xyz;
//     ABC abc;
//     xyz = &abc;

//     (*xyz).print();
//  //  xyz->print();

// class base{
//     public:
//     virtual void who()
//     {
//         cout<<"base class\n";
//     }
// };
//     class first_d: public base{
//         public:
//         void who()
//         {
//             cout<<"First derivation \n";
//         }
// };
//     class secound_d: public base
//     {
//         public:
//         void who()
//         {
//         cout<<"2nd detivation \n";
//         }
//     };

//     int main()
//     {
//         base base_obj;
//         base *p;
//         first_d first_obj;
//         secound_d secound_obj;
//         p = &base_obj;
//         p->who();
//         p = &first_obj;
//         p->who();
    
//    return 0;
// }

//-----------------------------------Pure virtual function------------------------------------->><<
//virtual void print() = 0;


//------------------------------->>Abstract class<<<-------------------
/*we can not make objects of abstract class,,, a class which have pure virtual funtion is abstract class*/

class shape{
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    ~shape()
    {
        cout<<"Shape is distructed !!! ";
    }
};

class circle : public shape
{
public:
    void draw()
    {
        cout<<"circle.draw()"<<endl;
    }
    void erase()
    {
        cout<<"circle.erase()"<<endl;
    }
    ~circle(){
        cout<<"Circle is distructed "<<endl;
    }
};


class square : public shape
{
public:
    void draw()
    {
        cout<<"square.draw()"<<endl;
    }
    void erase()
    {
        cout<<"square.erase()"<<endl;
    }
    ~square()
    {
        cout<<"square is distructed ";
    }
};

class triangle : public shape
{
public:
    void draw()
    {
        cout<<"triangle.draw()"<<endl;
    }
    void erase()
    {
        cout<<"triangle.erase()"<<endl;
    }
    ~triangle()
    {
        cout<<"Triangle is distructed ";
    }
};

int main()
{
    shape* p;
    char choice;
    do{
        cout<<"press 1 for circle \n";
        cout<<"press 2 for square \n";
        cout<<"press 3 for Triangle \n";
        cout<<"press 0 to exit \n";
        cin>>choice;
        if (choice == 1){
            p = new circle;
        }else if(choice == 2){
            p = new square;
        }else if(choice == 3){
            p = new triangle;
        }else{
            cout<<"Closing the menu ";
        }
    }while(choice>=1 && choice<=3);

    p->draw();
    p->erase();
    delete p;
    return 0;

}