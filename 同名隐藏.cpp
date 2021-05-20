#include<bits/stdc++.h>
using namespace std;
class A{
	private:
		int x,a;
	public:
		A(int x,int a){
			this->x=x;
			this->a=a;
		}
		int getX(){
			return x;
		}
		int getY(){
			return  a;
		}
		
};
class B{
	private:
		int x,a;
	public:
		B(int x,int a){
			this->x=x;
			this->a=a;
		}
		int getX(){
			return x;
		}
		int getA(){
			return  a;
		}
};
class C{
	private:
		int x,a;
	public:
		C(int x,int a){
			this->x=x;
			this->a=a;
		}
		int getX(){
			return x;
		}
		int getA(){
			return x;
		}
		int getB(){
			return a;
		}
};


class D:public A,public B,public C{
	int x,a;
public:
	D(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8):
		A(a1,a6),B(a2,a5),C(a3,a4),x(a7),a(a8){}
	int getX()const{
		return x;
	}
	int getA()const{
		return a;
	}
};

int main(){
	int a1,a2,a3,a4,a5,a6,a7,a8;
	cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8;
	D d(a1,a2,a3,a4,a5,a6,a7,a8);
	cout<<d.getX()<<" "<<d.A::getX()<<" "<<d.B::getX()<<endl;
	cout<<d.getY()<<endl;
	cout<<d.getA()<<" "<<d.B::getA()<<" "<<d.C::getA()<<endl;
	cout<<d.getB()<<endl;
	return 0;
}