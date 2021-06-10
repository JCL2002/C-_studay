#include<bits/stdc++.h>
using namespace std;
class Time{
	private:
		int hour,minute,second;
	public:
		Time(int hour,int minute,int second){
			this->hour=hour;
			this->minute=minute;
			this->second=second;
			}
		friend ostream& operator<<(ostream& out,const Time& t);
		void operator=(const Time& s){
			this->hour=s.hour;
			this->minute=s.minute;
			this->second=s.second;
		}
		Time& operator+(int s){
			int t=3600*hour+60*minute+second;
			t+=s;
			t%=86400;
			hour=t/3600;
			minute=(t-3600*(t/3600))/60;
			second=t%60;
			return  *this;
			}
		Time& operator-(int s){
			int t=3600*hour+60*minute+second;
			t-=s;
			if(t<0){
				t=86400-abs(t);
			}
			t%=86400;
			hour=t/3600;
			minute=(t-3600*(t/3600))/60;
			second=t%60;
			return  *this;
			}
		int operator-(const Time& t){
			int t1,t2;
			t1=3600*hour+60*minute+second;
			t2=3600*t.hour+60*t.minute+t.second;
			return t1-t2;
			}
};
ostream& operator<<(ostream& out,const Time& t){
	out << t.hour<<':'<<t.minute<<':'<<t.second<<endl;
	return out;
}
int main(){
	int s;
	cin>>s;
	Time t1(13,30,20);
	t1=t1-s;
	cout<<t1;
	Time t2(21,10,33);
	t2=t2+s;
	cout<<t2;
	cout<<t1-t2<<endl;
	return 0; 	
}