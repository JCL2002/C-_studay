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

	//����һ���ַ���
	getline(cin, str);
	//ʵ��������
	Test* s = new Test();
	//���ö����е����ݳ�Աֵ
	s->SetStr(str);
	cout << "��������ַ����ǣ�" << s->GetStr() << endl;
	cout << "�ַ�������Ϊ��" << s->GetLength() << endl;
	//���ַ����ߵ����
	cout << "���ַ������������";
	s->Reverse();
	//�ͷŶ���ռ�
	delete s;
	
	return 0;
}