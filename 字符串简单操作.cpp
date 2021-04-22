#include<bits/stdc++.h>
using namespace std;
class Test{
	private:
		string str;
	public:
		void SetStr(string str){
			this->str=str;
		}
		int GetLength(){
			return str.length();
		}
		void Reverse(){
			string b=str;
			reverse(b.begin(),b.end());
			cout << b;
		}
		string GetStr(){
			return str;
		}
};

int main()
{
	string str;

	//输入一个字符串
	getline(cin, str);
	//实例化对象
	Test* s = new Test();
	//设置对象中的数据成员值
	s->SetStr(str);
	cout << "您输入的字符串是：" << s->GetStr() << endl;
	cout << "字符串长度为：" << s->GetLength() << endl;
	//将字符串颠倒输出
	cout << "将字符串倒序输出：";
	s->Reverse();
	//释放对象空间
	delete s;
	
	return 0;
}