#include<bits/stdc++.h>
using namespace std;
#define PI 3.1515926
class Circle{
	double radius;
public:
	Circle(double r):radius(r){}
	double getRadius() const{
		return radius;
	}
	Circle(Circle &r)=delete;    //ɾ�����ƹ��캯��
	Circle(const Circle &r)=delete;  //ɾ�����ƹ��캯��
};

class Rectangle{ 
	double height,width;
public:
	Rectangle(double h,double w):height(h),width(w){}
	double getHeight()const{
		return height;
	}
	double getWidth()const{
		return width;
	}
	Rectangle(Rectangle &r)=delete;   //ɾ�����ƹ��캯��
	Rectangle(const Rectangle &r)=delete;   //ɾ�����ƹ��캯��
};
class Area{//�ƶ����캯��
	public:
		static double calArea(Circle &&p){
			return p.getRadius()*p.getRadius()*PI;
		}
		static double calArea(Rectangle &p){
			return p.getHeight()*p.getWidth();
		}
};
int main(){
	double r,h,w;
	cin>>r>>h>>w;
	const Circle c1(r);
	Circle c2(r+2);
	const Rectangle r1(h,w);
	Rectangle r2(h+2,w+2);
	cout<<Area::calArea(c1)<<endl;
	cout<<Area::calArea(c2)<<endl;
	cout<<Area::calArea(r1)<<endl;
	cout<<Area::calArea(r2)<<endl;
	return 0;
}
