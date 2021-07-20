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
			cout <<"x和y的和是"<<A::getX()+A::getY()<<endl;
//			cout <<"x和y的和是3"<<endl;//这一行可以直接这么写 
		}
};
class C:public A{
	public:
		C(int a,int b):A(a,b){
			
		}
		void doSomething(){
			cout <<"x和y的差是"<<A::getX()-A::getY()<<endl;
		}
};
class D:public A{
	public:
		D(int a,int b):A(a,b){
			
		}
		void doSomething(){
			cout <<"x和y的积是"<<A::getX()*A::getY()<<endl;
		}
};
/*
x和y的和是3

x和y的差是-1

x和y的积是30


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

