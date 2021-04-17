#include<iostream>
using namespace std;
class Date{
	public:
		int year;
		int month;
		int day;
};
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