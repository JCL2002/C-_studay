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
				cout <<"不能被0除"<<endl;
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
	//类的实例化 
	int a,b;
	cout<<"请依次输入a、b的值，空格隔开"<<endl;
	cin>>a>>b;
	cout<<"a+b= "<<ad.add(a,b)<<endl;
	cout<<"a-b= "<<su.sub(a,b)<<endl;
	cout<<"a*b= "<<mu.mul(a,b)<<endl;
	cout<<"a/b= "<<di.div(a,b)<<endl;
	return 0;
}
