#include<bits/stdc++.h>
using namespace std;
char MAIN[1000006];//主串
char MODE[1000006];//模式串
int NEXT[1000006];
void cal(int len){
	NEXT[0]=0;
	int j=0;
	for(int i=1;i<len;i++){
		while(j>0&&MODE[i]!=MODE[j]) j=NEXT[j-1];
		if(MODE[i]==MODE[j]) j++;
		NEXT[i]=j;
	}
}
int main(){
	cin >>MAIN;
	cin >>MODE;
	int len_main=strlen(MAIN);
	int len_mode=strlen(MODE);
	cal(len_mode);//计算next数组
	for(int i=0,j=0;i<len_main;i++){
		if(MAIN[i]!=MODE[j]){
			if(j==0)continue;
			j=NEXT[j-1];
			i--;
			continue;
		}
		j++;
		if(j==len_mode){
			cout <<i+2-len_mode<<endl;
			j=NEXT[j-1];
		}
	}
	for(int i=0;i<len_mode;i++){
		cout <<NEXT[i]<<' ';
	}
	return 0;
}