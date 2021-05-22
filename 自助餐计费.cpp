#include<bits/stdc++.h>
using namespace std;
class Customer{
	public:
		string gender;
		Customer(string gender){
			this->gender=gender;
		}
		virtual float calculateCost(char choose)=0;
};
class AdultCustomer:public Customer{
	public:
		AdultCustomer(string gender):Customer(gender){}
		float calculateCost(char choose){
			if(gender[0]=='m'){
				switch (choose){
					case 'A':{
						return 115;
						break;
					}
					case 'B':{
						return 138;
						break;
					}
					default:{
						return 172.5;
						break;
					}
				}
			}
			else{
				switch (choose){
					case 'A':{
						return 105;
						break;
					}
					case 'B':{
						return 126;
						break;
					}
					default:{
						return 157.5;
						break;
					}
				}
			}
		}
};
class UnderAgeCustomer:public Customer{
	public:
		UnderAgeCustomer(string gender):Customer(gender){}
		float calculateCost(char choose){
			switch (choose){
				case 'A':{
					return 70;
					break;
				}
				case 'B':{
					return 84;
					break;
				}
				default:{
					return 105;
					break;
				}
			}
		}
};
class ElderlyCustomer:public Customer{
	public:
		ElderlyCustomer(string gender):Customer(gender){
		}
		float calculateCost(char choose){
			switch (choose){
				case 'A':{
					return 95;
					break;
				}
				case 'B':{
					return 120*0.85+12;
					break;
				}
				default:{
					return 150*0.85+15;
					break;
				}
			}
		}
};
int main(){ 

	AdultCustomer c1("male");            

	AdultCustomer c2("female");  

	ElderlyCustomer c3("male");

	UnderAgeCustomer c4("female");

	Customer *p;

	char set1,set2,set3,set4;

	cin>>set1>>set2>>set3>>set4;

	p=&c1;

	cout<<p->calculateCost(set1)<<endl;

	p=&c2;

	cout<<p->calculateCost(set2)<<endl;

	p=&c3;

	cout<<p->calculateCost(set3)<<endl;

	p=&c4;

	cout<<p->calculateCost(set4)<<endl;

	return 0;

}