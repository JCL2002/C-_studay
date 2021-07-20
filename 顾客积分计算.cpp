#include<bits/stdc++.h>
using namespace std;
class Customer{
	public:
		double score;
		virtual double getPoints()=0;
		virtual void recordPoints(double m)=0;
};
class  OrdinaryCustomer:public Customer{
	public:
		OrdinaryCustomer(double m){
			this->score=m;
		}
		double getPoints(){
			return score;
		}
		void recordPoints(double m){
			score=m*0.2;
		}
};
class MemberCustomer:public Customer{
	public:
		MemberCustomer(double m){
			this->score=m;
		}
		double getPoints(){
			return score;
		}
		virtual void recordPoints(double m){
			score=m*0.3;
		}
};
class VIPCustomer:public Customer{
	public:
		VIPCustomer(double m){
			this->score=m;
		}
		double getPoints(){
			return score;
		}
		void recordPoints(double m){
			score=m*0.3*1.2;
		}
};
int main(){	

	OrdinaryCustomer oc(0);  

	MemberCustomer mc(0);

	VIPCustomer vc(0);

	Customer *p;  

	double m1,m2,m3;

	cin>>m1>>m2>>m3;

	p=&oc;

	p->recordPoints(m1); 

	cout<<p->getPoints()<<endl;

	p=&mc;

	p->recordPoints(m2);

	cout<<p->getPoints()<<endl;

	p=&vc;

	p->recordPoints(m3);

	cout<<p->getPoints()<<endl;

	return 0;

}