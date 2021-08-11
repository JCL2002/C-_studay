#include<bits/stdc++.h>
using namespace std;
char s[1002][1002];
int score[1002];
int num[256];

int n,m;

int mmax(int x){
	memset(num,0,256*sizeof(int));
	for(int i=0;i<n;i++){
		num[(int)s[i][x]]++;
	}
	int M=0;
	for(int i=0;i<256;i++){
		M=max(M,num[i]);
	}
	return M;
}
int main(){
	cin >>n>>m;
	for(int i=0;i<n;i++){
		cin >>s[i];
	}
	for(int i=0;i<m;i++){
		cin >>score[i];
	}
	long long sum=0;
	for(int i=0;i<m;i++){
		sum+=mmax(i)*score[i];
	}
	cout <<sum;
	return 0;
}