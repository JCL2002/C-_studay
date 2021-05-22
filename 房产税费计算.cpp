#include<bits/stdc++.h>
using namespace std;
class HouseProperty{
	public:
		double area;
		double unitPrice;
		HouseProperty(double area,double unitPrice){
			this->area=area;
			this->unitPrice=unitPrice;
		}
		virtual double taxCalculation()=0;
};
class Shop:public HouseProperty{
	public:
		Shop(double area,double up):HouseProperty(area,up){
		}
		double taxCalculation(){
			double price=area*unitPrice;
			if(area<=(double)30){
				return 0.03*price;
			}
			if(area<=(double)100){
				return 0.04*price;
			}
			return 0.05*price;
		}
};
class Residence:public HouseProperty{
	public:
		Residence(double area,double up):HouseProperty(area,up){}
		virtual double taxCalculation(){
			if(area<=(double)90){
				return area*unitPrice*0.015;
			}
			return area*unitPrice*0.02;
		}
};
class Villa:public Residence{//直接继承HouseProperty类不香吗
	public:
		Villa(double area,double up):Residence(area,up){}
		double taxCalculation(){
			return area*unitPrice*0.05+100000;
		}
};
int main(){	

	double area;          

	double unitPrice; 

	cin>>area>>unitPrice;

	Residence h1(area,unitPrice);    

	cin>>area>>unitPrice;         

	Shop h2(area,unitPrice);

	cin>>area>>unitPrice; 

	Villa h3(area,unitPrice);

	HouseProperty *p;

	p=&h1;

	cout<<p->taxCalculation()<<endl;

	p=&h2;

	cout<<p->taxCalculation()<<endl;

	p=&h3;

	cout<<p->taxCalculation()<<endl;

	return 0;

}