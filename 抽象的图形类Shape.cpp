#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926
class Shape{
	public:
		virtual double getArea()=0;
		virtual double getPerim()=0; 
};
//从前有座山
//山里有个面
//庙里有个老和尚给小和尚讲故事
//讲的什么呢
//goto line 8
class Rectangle:public Shape{
	public:
		double length,width;
		Rectangle(double length,double width){
			this->length=length;
			this->width=width;
		}
		double getArea(){
			return length*width;
		}
		double getPerim(){
			return 2*(length+width);
		}
};
class Circle:public Shape{
	public:
		double radius;
		Circle(double radius){
			this->radius=radius;
		}
		double getArea(){
			return PI*radius*radius;
		}
		double getPerim(){
			return 2*PI*radius;
		}
};
int main() {

	double length,width,radius;

	cin>>length>>width;

	cin>>radius;

	Rectangle rectangle(length, width);

	Circle circle(radius);

	Shape *p;

	//计算长方形面积和周长

	p = &rectangle;

	cout << p->getArea() << endl;

	cout << p->getPerim() << endl;

	//计算圆形面积和周长

	p = &circle;

	cout << p->getArea() << endl;

	cout << p->getPerim() << endl;

	return 0;

}