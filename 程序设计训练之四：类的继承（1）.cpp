#include <iostream>

using namespace std;

class Father{

    int a;

public:

    Father(int a):a(a){

        cout<<"Father Constructed "<<a<<endl;

    }

    void doSomething(){

        cout<<"Hello Father"<<endl;

    }

};

class Mother{

    int b;

public:

    Mother(int b):b(b){

        cout<<"Mother Constructed "<<b<<endl;

    }

    void doSomething(){

        cout<<"Hello Mother"<<endl;

    }

};
class Son:public Mother,public Father{
	public:
		Son(int a,int b,int c,int d,int e):Mother(a),Father(b){
			cout<<"Father Constructed "<<c<<endl;
			cout<<"Mother Constructed "<<d<<endl;
			cout<<"Son Constructed "<<e<<endl;
		}
		void doSomething(){
			Father::doSomething();
			Mother::doSomething();
			cout <<"Hello Son"<<endl;
		}
};
/*
Êä³ö£º
Mother Constructed 1

Father Constructed 2

Father Constructed 3

Mother Constructed 4

Son Constructed 5

Hello Father

Hello Mother

Hello Son



*/
int main(){

    Son son(1,2,3,4,5);

    son.doSomething();

    return 0;

}