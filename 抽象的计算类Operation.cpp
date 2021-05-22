#include<bits/stdc++.h>
using namespace std;
class Operation{
	public:
		int a,b;
		Operation(int a,int b){
			this->a=a;
			this->b=b;
		}
		virtual int getResult();
};
class Add:public Operation{
	public:
		Add(int a,int b):Operation(a,b){
			
		}
		int getResult(){
			return a+b;
		}
};
class Sub:public Operation{
	public:
		Sub(int a,int b):Operation(a,b){
			
		}
		int getResult(){
			return a-b;
		}
};
class Product:public Operation{
	public:
		Product(int a,int b):Operation(a,b){
			
		}
		int getResult(){
			return a*b;
		}
};
class SumOfSquares:public Operation{
	public:
		SumOfSquares(int a,int b):Operation(a,b){
			
		}
		int getResult(){
			return a*a+b*b;
		}
};
int main(){
	int numA,numB;
	cin>>numA>>numB;
	Add add(numA,numB);	  //��	 
	Sub sub(numA,numB);  //�� 
	Product pro(numA,numB);  //�˻� 
	SumOfSquares sos(numA,numB); //ƽ���� 
	Operation *op;			
	op=&add;
	cout<<op->getResult()<<endl;		 
	op=&sub;
	cout<<op->getResult()<<endl;
	op=&pro;
	cout<<op->getResult()<<endl;
	op=&sos;
	cout<<op->getResult()<<endl;
	return 0;
}