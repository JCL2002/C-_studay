#include<bits/stdc++.h>
using namespace std;
class Test{
	private:
		int a, b;
		float f1, f2;
	public:
		int GetMax(int a,int b){
			if(a>b){
				return a;
			}
			else{
				return b;
			}
		}
		float GetMax(float a,float b){
			if(a>b){
				return a;
			}
			else{
				return b;
			}
		}
		string GetMax(string a,string b){
			if(a.compare(b)){
				return b;
			}
			else{
				return a;
			}
		}
};
int main()
{
	int a, b;
	float f1, f2;
	string str1, str2;
	Test s;

	cin >> a >> b;
	cin >> f1 >> f2;
	cin.get();
	getline(cin, str1);
	getline(cin, str2);

	cout << "两个int数中较大的为：" << s.GetMax(a, b) << endl;
	cout << "两个float数中较大的为：" << s.GetMax(f1, f2) << endl;
	cout << "两个string中较大的为：" << s.GetMax(str1, str2) << endl;
}