#include <bits/stdc++.h>
using namespace std;

//��ǰ����ɽ
//ɽ���и���
//�����и��Ϻ��и�С���н�����
//����ʲô��
void fun1(){
	void fun4();
	cout <<"����ʲô��"<<endl;
	fun4();
}

void fun2(){
	cout <<"�����и��Ϻ��и�С���н�����"<<endl;
	fun1();
}

void fun3(){
	cout <<"ɽ���и���"<<endl;
	fun2();
}

void fun4() {
	cout << "��ǰ����ɽ" << endl;
	fun3();
}
class Date{
	public://��Ҫ���Լ����鷳
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
			srand(time(NULL));//��ʼ������� 
			if(rand()==114514){
				fun4();//�ֺ�С�ļ��ʳ�����
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