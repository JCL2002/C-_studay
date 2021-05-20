#include<bits/stdc++.h>
using namespace std;
class Base1{
	int id;
public:
	Base1(int id):id(id){
		cout<<"Base1 Constructed,ID:"<<id<<endl;
	}
	~Base1(){
		cout<<"Base1 Destructed,ID:"<<id<<endl;
	}
};

class Base2{
	int id;
public:
	Base2(int id):id(id){
		cout<<"Base2 Constructed,ID:"<<id<<endl;
	}
	~Base2(){
		cout<<"Base2 Destructed,ID:"<<id<<endl;
	}
};  

class Base3{
	int id;
public:
	Base3(int id):id(id){
		cout<<"Base3 Constructed,ID:"<<id<<endl;
	}
	~Base3(){
		cout<<"Base3 Destructed,ID:"<<id<<endl;
	}
}; 
class Derived{
	public:
		int id;
		Base3 e3;Base1 a1;Base2 c2;Base2 d2; Base1 b1;Base3 f3;
		Derived(int id1,int id2,int id3,int id4,int id5,int id6,int id7):
			e3(id6),a1(id4),c2(id5),d2(id2),b1(id1),f3(id3),id(id7)
			
		{
			cout <<"Derived Constructed,ID:"<<id<<endl;
			cout <<"Derived Destructed,ID:"<<id<<endl;
		}
};
int main(){
	int id1,id2,id3,id4,id5,id6,id7;
	cin>>id1>>id2>>id3>>id4>>id5>>id6>>id7;
	Derived d(id1,id2,id3,id4,id5,id6,id7);
	return 0;
}