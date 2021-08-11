#include<bits/stdc++.h>
using namespace std;
char a[1000006];
char b[1000006];
int A[256];
int B[256];
void init(){
	for(int i=0;i<256;i++){
		A[i]=B[i]=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		int n,k;
		cin >>n>>k;
		cin >>a;
		cin >>b;
		init();
		//统计a，b中各个字母出现的次数
		for(int i=0;i<n;i++){
			A[(int)a[i]]++;
			B[(int)b[i]]++;
		}
		bool flag=true;
//		for(int i=(int)'a';i<(int)'z';i++){
//			cout <<(char)i<<":  "<<A[i]<<'\t';
//		}
		for(int i=(int)'a';i<(int)'z';i++){
//			printf("A[%d]: %d\tB[%d]: %d\t",i,A[i],i,B[i]);
			if(A[i]>=B[i]&&(A[i]-B[i])%k==0){
				A[i+1]+=(A[i]-B[i]);
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag)cout <<"Yes"<<endl;
		else cout <<"No"<<endl;
	}
	return 0;
}