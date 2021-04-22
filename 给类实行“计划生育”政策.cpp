#include<bits/stdc++.h>
using namespace std;
class A{
	private:
		static int NUM;
		A(string name){
			this->name=name;
		}
		string name;
	public:
		static A* GetObject(string name){
			if(!A::NUM){
				
				return &A(name);
			}
			
		}
		void Print(){
			cout << name <<endl;
		}
};
int A::NUM=0;
int main() {
	string name1,name2;
	cin >> name1;
	cin >> name2;

	A* o1 = A::GetObject(name1);
	o1->Print();


	A* o2 = A::GetObject(name2);
	o2->Print();

	if (o1 == o2)
	{
		cout << "o1与o2指向的是同一个对象！" << endl;
	}

	delete o1;

	return 0;
}