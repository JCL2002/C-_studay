#include<bits/stdc++.h>
using namespace std;
class Test{
	private:
		int a;
		string s;
	public:
		int DataLength(int a){
			int len=0;
			while(a){
				a/=10;
				len++;
			}
			return len;
		}
		int DataLength(string s){
			return s.length();
		}
};

int main(){
	int a;
	string s;
	getline(cin,s);
	cin>>a;
	Test t;
	cout<<t.DataLength(s)<<endl;
	cout<<t.DataLength(a)<<endl;
        return 0;
}