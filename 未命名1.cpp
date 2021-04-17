#include<iostream>
using namespace std;
class ADD{
	public:
		int add(int a,int b){
			
			return a+b;
		}
};


int main(){
	class ADD ad;
	int c=1,d=2;int sum;
	sum=ad.add(c,d);
	cout << sum;
	return 0;
}
