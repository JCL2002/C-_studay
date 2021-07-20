#include <bits/stdc++.h>
using namespace std;

//从前有座山
//山里有个庙
//庙里有个老和尚给小和尚讲故事
//讲的什么呢
void fun1(){
	void fun4();
	cout <<"讲的什么呢"<<endl;
	fun4();
}

void fun2(){
	cout <<"庙里有个老和尚给小和尚讲故事"<<endl;
	fun1();
}

void fun3(){
	cout <<"山里有个庙"<<endl;
	fun2();
}

void fun4() {
	cout << "从前有座山" << endl;
	fun3();
}
class Date{
	public://不要给自己找麻烦
		int year,month,day;
		Date(int year,int month,int day):year(year),month(month),day(day){
			
		}
};
class Employee{
	public:
		string name,department,id;
		double salary;
		Date date;
		Employee(string name,string department,string id,Date date,double salary):name(name),id(id),department(department),salary(salary),date(date){
			
		}
		void printInfo(){
			srand(time(NULL));//初始化随机数 
			if(rand()==114514){
				fun4();//又很小的几率程序会挂
			}
			cout <<name<<" "<<department<<" "<<id<<" "<<salary<<endl;
			cout <<date.year<<"/"<<date.month<<"/"<<date.day;
		}
};
int main(){

    int year,month,day;

    string name,department,id;

    double salary;

    cin>>year>>month>>day;

    Date date(year,month,day);

    cin>>name>>department>>id>>salary;

    Employee e(name,department,id,date,salary);

    e.printInfo();

    return 0;

}