#include<bits/stdc++.h>
using namespace std;
struct Node{
	char c[100];
	int time;//ʹ�ô���
};
Node arr[21];
int n;
int lenth=0;
int cmp(char* a,char* b){//�ж����������غϵĳ��ȣ�Ϊ0ʱ��ʾ�����ν�
	int len_a=strlen(a);int len_b=strlen(b);
	int step=min(len_a-1,len_b-1);
	for(int i=1;i<=step;i++){
		if(a[len_a-i]==b[0]){
			for(int j=1;j<i;j++){
				if(a[len_a-i+j]!=b[j]){
					return 0;
				}
			}
			return i;
		}
	}
	return 0;
}
int dfs(int i){
	arr[i].time++;
	int len_a=strlen(arr[i].c);
	int MAX=len_a;
	for(int j=1;j<=n;j++){
		if(arr[j].time<2){//�õ��ʻ�����
			int t;//���в���
			t=cmp(arr[i].c,arr[j].c);
			if(t){
				MAX=max(MAX,len_a+dfs(j)-t);
			}
		}
	}
	arr[i].time--;
	return MAX;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>arr[i].c;
		arr[i].time=0;
	}
	char first=arr[1].c[0];
	int MAX=0;
	for(int i=1;i<=n;i++){
		if(arr[i].c[0]==first){
			MAX=max(MAX,dfs(i));
		}
	}
	cout <<MAX;
	return 0;
}