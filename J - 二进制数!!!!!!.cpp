#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,m=1;
	int times;
	cin >>times;
	for(int k=0;k<times;k++){
	cin >> n;
	int number=0;//1的个数
	int i=-1;//最高位的位置
	for(int j=0;j<64;j++){
		if(n&(m<<j)){
			number++;
			i=j;
		}
	}
	i-=(number-1);
	if(n==0){
		cout <<'0'<<endl;
	}
	else{
		bool mark=true;
		for(int j=0;j<=i;j++){
			if(mark){
				cout <<'1';
				mark=false;
			}
			else{
				cout << '0';
			}
		}
		cout<<endl;
	}
	}
	return 0;
}