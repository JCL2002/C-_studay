#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265
class Circle{
	private:
		double x,y,radius;
	public:
		Circle(double x,double y,double r){
			this->x=x;
			this->y=y;
			this->radius=r;
			}
		friend double operator+(const Circle& c1,const Circle& c2);
		void operator+(double a){
			this->x+=a;
			this->y+=a;
			this->radius+=a;
			}
		friend ostream& operator<<(ostream& out,const Circle& c);
};
double operator+(const Circle& c1,const Circle& c2){
	return pi*c1.radius*c1.radius+pi*c2.radius*c2.radius;
}
ostream& operator<<(ostream& out,const Circle& c){
	out <<"圆心："<<c.x<<','<<c.y<<" 半径："<<c.radius<<endl;
	return out;
}
int main(){

	double x,y,r,n;

	cin>>x>>y>>r>>n;

	Circle c1(x,y,r);

	Circle c2=c1;

	c2+n;

	cout<<c1;

	cout<<c2;

	cout<<c1+c2<<endl;

	return 0;


}