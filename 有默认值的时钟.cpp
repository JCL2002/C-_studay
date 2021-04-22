#include<bits/stdc++.h>
using namespace std;

class Clock{
	private:
		int hour;
		int minute;
		int second;
	public:
		Clock(){//默认构造函数
			hour=0;
			minute=0;
			second=0;
		}
		Clock(int hour){
			this->hour=hour;
			minute=30;
			second=40;
		}
		Clock(int hour,int minute){
			this->hour=hour;
			this->minute=minute;
			second=40;
		}
		Clock(int hour,int minute,int second){
			this->hour=hour;
			this->minute=minute;
			this->second=second;
		}
		void Display(){
			cout << hour <<':'<<minute<<':'<<second<<endl;
		}
		void SetValue(int hour=0,int minute=30,int second=40){
			this->hour=hour;
			this->minute=minute;
			this->second=second;
		}
};

int main()
{
	Clock o1(14);
	Clock o2(15, 40);
	Clock o3(15, 40, 59);
	Clock o4;

	o1.Display();
	o2.Display();
	o3.Display();
	o4.Display();
	o4.SetValue(23);
	o4.Display();

	return 0;
}