#include<iostream>
using namespace std;
class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(int year,int month,int day);
		int Y(){
			return year;
		}
		int M(){
			return month;
		}
		int D(){
			return day;
		}
};
Date::Date(int year,int month,int day){
	this->year=year;
	this->month=month;
	this->day=day;
}
class Employee{
	private:
		string ID;
		string name;
		Date date;
	public:
		Employee(string ID,string name,Date date){
			this->ID=ID;
			this->name=name;
			this->date=date;
	}
};
int main(){
	
	return 0;
}