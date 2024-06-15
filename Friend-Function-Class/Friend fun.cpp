#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		void setNumber(int n1,int n2)
		{
			a=n1;
			b=n2;
		}
		friend Complex sumComplex(Complex o1, Complex o2);
		void printnum()
		{
			cout<<"Your Number is "<<a<<" + "<<b<<"i"<<endl;
		}
};

Complex sumComplex(Complex o1, Complex o2)
{
	Complex o3;
	o3.setNumber((o1.a + o2.a), (o1.b+ o2.b));
	return o3;
}

int main()
{
	Complex c1,c2,sum;
	c1.setNumber(1,5);
	c2.setNumber(5,30);
	
	c1.printnum();
	c2.printnum();
	
	sum=sumComplex(c1,c2);
	
	sum.printnum();
	
	
	return 0;
}
