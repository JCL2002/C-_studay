#include<bits/stdc++.h>
using namespace std;
class MyString{
	private:
		string s;
		static int NUM;
	public:
		MyString(string s){
			this->s=s;
			NUM++;
		}
		static int GetN(){
			return NUM;
		}
		static string GetString(MyString *s){
			return s->s;
		}
		~MyString(){
			NUM--;
		}
};
int MyString::NUM=0;
int main()
{
	MyString* str1 = new MyString("one");
	MyString* str2 = new MyString("two");
	MyString* str3 = new MyString("three");

	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str1) << endl;
	delete str1;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str2) << endl;
	delete str2;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	cout << "我是对象：" << MyString::GetString(str3) << endl;
	delete str3;
	cout << "目前对象个数为：" << MyString::GetN() << endl;
	return 0;
}