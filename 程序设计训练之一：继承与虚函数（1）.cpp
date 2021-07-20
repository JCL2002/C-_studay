#include<bits/stdc++.h>
using namespace std;
class A{

    int x,y;

public:

    A(int a,int b):x(a),y(b){}

    int getX()const{return x;}

    int getY()const{return y;}

    virtual void doSomething()=0;

};
class B:public A{
	public:
		B(int a,int b):A(a,b){
			
		}
		void doSomething(){
			cout <<"x��y�ĺ���"<<A::getX()+A::getY()<<endl;
//			cout <<"x��y�ĺ���3"<<endl;//��һ�п���ֱ����ôд 
		}
};
class C:public A{
	public:
		C(int a,int b):A(a,b){
			
		}
		void doSomething(){
			cout <<"x��y�Ĳ���"<<A::getX()-A::getY()<<endl;
		}
};
class D:public A{
	public:
		D(int a,int b):A(a,b){
			
		}
		void doSomething(){
			cout <<"x��y�Ļ���"<<A::getX()*A::getY()<<endl;
		}
};
/*
x��y�ĺ���3

x��y�Ĳ���-1

x��y�Ļ���30


*/

int main(){

    A *ap;

    B b(1,2);

    C c(3,4);

    D d(5,6);

    ap=&b;

    ap->doSomething();

    ap=&c;

    ap->doSomething();

    ap=&d;

    ap->doSomething();

    return 0;

}

