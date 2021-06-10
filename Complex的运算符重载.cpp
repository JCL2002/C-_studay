#include<bits/stdc++.h>
using namespace std;
class Complex{
	private:
		double real,imag;
	public:
		Complex(const Complex& c){
			this->real=c.real;
			this->imag=c.imag;
			}
		Complex(double r,double i){
			real=r;
			imag=i;
			}
		friend ostream& operator<<(ostream& out,const Complex& c);
		friend Complex operator*(const Complex& c1,const Complex& c2);
		friend Complex operator+(const Complex& c1,const Complex& c2);
		void operator+(double a){
			this->real+=a;
			this->imag+=a;
			}
		~Complex(){}
};
ostream& operator<<(ostream& out,const Complex& c){
	out <<c.real<<'+'<<c.imag<<'i'<<endl;
	return out;
}
Complex operator*(const Complex& c1,const Complex& c2){
	Complex c(c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+c2.real*c1.imag);
	return c;
}

Complex operator+(const Complex& c1,const Complex& c2){
	Complex c(c1.real+c2.real,c1.imag+c2.imag);
	return c;
}
int main(){

	double real1,imag1,real2,imag2;

	cin>>real1>>imag1>>real2>>imag2;

	Complex c1(real1,imag1),c2(real2,imag2);   

	cout<<c1;

	cout<<c2;                   

	Complex c3=c1*c2;                  

	cout<<c3;

	c3+3;

	cout<<c3;

	return 0;


}