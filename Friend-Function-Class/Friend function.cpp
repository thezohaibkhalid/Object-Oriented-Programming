#include<iostream>
using namespace std;

// Forward Declaration
class Complex;

class Calculator
{
	public:
		int add(int a, int b)
		{
			return a+b;
		}
		int sumrealcomplex(Complex, Complex);
};

class Complex
{
	private:
		int a, b;
		friend int Calculator::sumrealcomplex(Complex o1, Complex o2);

	public:
		void setNumber(int n1, int n2)
		{
			a = n1;
			b = n2;
		}

		void getNumber()
		{
			cout << "Your number is " << a << " + " << b << "i" << endl;
		}
};

int Calculator::sumrealcomplex(Complex o1, Complex o2)
{
	return (o1.a + o2.a);
}

int main()
{
	Complex o1,o2;
	o1.setNumber(1,4);
	o2.setNumber(5,7);
	Calculator cal;
	int result = cal.sumrealcomplex(o1,o2);
	cout<<"The sum of real part of o1 and o2 is "<<result<<endl;
	return 0;
}

