#include<bits/stdc++.h>
using namespace std;
class Base1{
	public:
	void doSomething(){
		cout <<"Hello Base1"<<endl;
	}
};
class Base2:public Base1{
	public:
		int times;
		Base2(){
			times=0;
		}
		void doSomething(){
			if(times){
				cout <<"Hello Base1"<<endl;
			}
			else{
				cout <<"Hello Base2"<<endl;
			}
			times++;
		}
};
class Derived1:public Base2{
	public:
		void doSomething(){
			cout <<"Hello Base1"<<endl<<"Hello Base2"<<endl<<"Hi Derived1"<<endl;
		}
};
class Derived2:public Base1{
	public:
		void doSomething(){
			cout << "Hello Base1"<<endl<<"Hi Derived2"<<endl;
		}
};
int main(){
	Base1 b1;
	Base2 b2;
	Derived1 d1;
	Derived2 d2;
	Base1 *bp;
	bp=&b2;
	bp->doSomething();  //(1)
	cout<<endl;
	
	bp=&d1;
	bp->doSomething();  //(2)
	cout<<endl;
	
	bp=&d2;
	bp->doSomething();   //(3)
	cout<<endl;
	
	Base2 &br=d1;
	br.doSomething();   //(4)
	cout<<endl;
	
	d1.doSomething();   //(5)
	cout<<endl;
	
	d2.doSomething();   //(6)
	return 0;
}