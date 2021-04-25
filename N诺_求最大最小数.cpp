#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,N=0;
	int list[10000];
	int min,max;
	do{
		n=N;
		cin>>N;
		if(n==N){
			break;
		}
		for(int j=0;j<N;j++){
			cin >>list[j];
		}
		min=list[0];
		max=list[0];
		for(int j=1;j<N;j++){
			if(list[j]>max){
				max=list[j];
			}
			else if(list[j]<min){
				min=list[j];
			}
		}
		cout << max <<" "<<min<<endl;
	}while(true);
}