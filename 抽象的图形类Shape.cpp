#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926
class Shape{
	public:
		virtual double getArea()=0;
		virtual double getPerim()=0; 
};
//��ǰ����ɽ
//ɽ���и���
//�����и��Ϻ��и�С���н�����
//����ʲô��
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

	//���㳤����������ܳ�

	p = &rectangle;

	cout << p->getArea() << endl;

	cout << p->getPerim() << endl;

	//����Բ��������ܳ�

	p = &circle;

	cout << p->getArea() << endl;

	cout << p->getPerim() << endl;

	return 0;

}