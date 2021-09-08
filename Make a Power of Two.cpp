#include<bits/stdc++.h>
using namespace std;
long long arr[60];
char t[60][22];
void turn(int i){
	char cache[20];
	cache[0]='\0';
	int n=0;
	while(arr[i]){
		cache[++n]=(char)(arr[i]%10+'0');
		arr[i]/=10;
	}
	int si=0;
	for(;n>0;n--){
		t[i][si++]=cache[n];
	}
	t[i][si]='\0';
}
int main(){
	long long base=2;
	arr[0]=1;
	for(int i=1;i<=59;i++){
		arr[i]=base;
		base*=2;
		turn(i);
	}
	t[0][0]='1';
	t[0][1]='\0';
//	for(int i=0;i<=34;i++) cout <<t[i]<<endl;
	int T;
	cin >>T;
	while(T--){
		string s;
		cin >>s;
		int mmin=1000000;
		int len=s.length();
		for(int i=0;i<=59;i++){
			int pear=0;//Æ¥ÅäµÄ¶ÔÊý
			int len_t=strlen(t[i]);
			for(int j=0;j<len;j++){
				if(t[i][pear]==s[j])pear++;
			}
			mmin=min(mmin,len+len_t-2*pear);
		}
		cout <<mmin<<endl;
	}
	return 0;
}