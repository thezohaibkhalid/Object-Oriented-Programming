#include<iostream>
using namespace std;

class A{
private:
    int a,b;
public:
    int c;
protected:
    void getter(){
        cout<<"Enter the value of A :";
        cin>>a;
        cout<<"Enter the value of B :";
        cin>>b;
    }
    void add(){
        cout<<"A plus B is Equal to "<<a+b;
    }

    class B: protected A{
    public:
        B(){
            getter();
            add();
        }
    };
};

int main(){
    B addition;
}
/*

#include<iostream>
using namespace std;
class parent{
    int a,b;
public:
    int c;
    void show(){
        cout<<"show function";}

protected:
    int d;
    void display(){
        cout<<"values of a and b are\n"<<a<<b<<endl;

    }
    void setter(int var){
        a=var;
        b=var;
    }

};
class child:public parent{
public:
    child(){
        setter(10);
        display();
    }

};
int main(){

    child c;

}
*/
