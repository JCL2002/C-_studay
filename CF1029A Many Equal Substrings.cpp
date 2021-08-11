#include<bits/stdc++.h>
using namespace std;
int n,k;
char t[55];
char res[5550];
int NEXT[55];
void cal(){
	int j=0;
	NEXT[0]=0;
	for(int i=1;i<n;i++){
		while(j>0&&t[i]!=t[j]) j=NEXT[j-1];
		if(t[i]==t[j]) j++;
		NEXT[i]=j;
	}
}
int main(){
	cin >>n>>k;
	cin >>t;
	cal();
//	cout <<"here"<<endl;
//	for(int i=0;i<n;i++) cout <<NEXT[i]<<' ';
	int size=NEXT[n-1];//最大相等前后缀
	int num=0;
	for(int i=0;i<size;i++){
		res[num++]=t[i];
	}
	for(int i=0;i<k;i++){
		for(int j=size;j<n;j++){
			res[num++]=t[j];
		}
	}
	for(int i=0;i<num;i++){
		printf("%c",res[i]);
	}
	return 0;
}