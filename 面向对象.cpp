#include<iostream>
using namespace std;
class ADD{
	public:
		int add(int a,int b){
			return a+b;
		}
};
class SUB{
	public:
		int sub(int a,int b){
			return a-b;
		}
};
class MUL{
	public:
		int mul(int a,int b){
			return a*b;
		}
};
class DIV{
	public:
		int div(int a,int b){
			if(!b){
				cout <<"���ܱ�0��"<<endl;
				return 0;
			}
			else{
				return a/b;
			}
		}
};


int main(){
	
	class ADD ad;
	class SUB su;
	class MUL mu;
	class DIV di;
	//���ʵ���� 
	int a,b;
	cout<<"����������a��b��ֵ���ո����"<<endl;
	cin>>a>>b;
	cout<<"a+b= "<<ad.add(a,b)<<endl;
	cout<<"a-b= "<<su.sub(a,b)<<endl;
	cout<<"a*b= "<<mu.mul(a,b)<<endl;
	cout<<"a/b= "<<di.div(a,b)<<endl;
	return 0;
}
