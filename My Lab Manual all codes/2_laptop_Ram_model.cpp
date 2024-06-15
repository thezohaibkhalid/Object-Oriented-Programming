//
// Created by zohaib on 29/05/2023.
//
/*Q#.1: Write a C++ program that creates a class called laptop. The data members of the class
        are brand (string), model (string), serial (int), color (string), price (float),
        processor speed (float), RAM (int), screen size(float). Create member function
        that will set the individual values. Since the RAM can be upgraded therefore create
        a function that allows you to upgrade the RAM only. In the end, create a function
        that will display all the data members.*/

#include<iostream>
using namespace std;

class Laptop{
private:
    string brand;
    string model;
    string serial;
    string color;
    float price;
    float processor_speed;
    int RAM;
    float screen_size;
public:
    void set_values(){
        cout<<"Enter brand: ";
        cin>>brand;
        cout<<"Enter model: ";
        cin>>model;
        cout<<"Enter serial: ";
        cin>>serial;
        cout<<"Enter color: ";
        cin>>color;
        cout<<"Enter price: ";
        cin>>price;
        cout<<"Enter processor speed: ";
        cin>>processor_speed;
        cout<<"Enter RAM: ";
        cin>>RAM;
        cout<<"Enter screen size: ";
        cin>>screen_size;
    }
    void display_values(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Serial: "<<serial<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Processor Speed: "<<processor_speed<<endl;
        cout<<"RAM: "<<RAM<<endl;
        cout<<"Screen Size: "<<screen_size<<endl;
    }
};
int main(){
    Laptop xyz;
    xyz.set_values();
    xyz.display_values();
    return 0;
}
