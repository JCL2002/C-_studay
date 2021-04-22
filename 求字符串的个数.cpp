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

	cout << "Ŀǰ�������Ϊ��" << MyString::GetN() << endl;
	cout << "���Ƕ���" << MyString::GetString(str1) << endl;
	delete str1;
	cout << "Ŀǰ�������Ϊ��" << MyString::GetN() << endl;
	cout << "���Ƕ���" << MyString::GetString(str2) << endl;
	delete str2;
	cout << "Ŀǰ�������Ϊ��" << MyString::GetN() << endl;
	cout << "���Ƕ���" << MyString::GetString(str3) << endl;
	delete str3;
	cout << "Ŀǰ�������Ϊ��" << MyString::GetN() << endl;
	return 0;
}