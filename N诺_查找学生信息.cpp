#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M,n=0,m=0;
	while(true){
		cin >>N>>M;
		if(N==n&&m==M){
			break;
		}
		vector<int>B(M+1);
		vector<int>reader(N);
		for(int j=0;j<=M;j++){
			B[j]=0;
		}
		for(int j=0;j<N;j++){
			cin >>reader[j];
			B[reader[j]]++;
		}
		for(int j=0;j<N;j++){
			if(B[reader[j]]>1){
				cout <<B[reader[j]]-1<<endl;
			}
			else{
				cout <<"Beiju"<<endl;
			}
		}
		n=N;m=M;
	}
	
	return 0;
}