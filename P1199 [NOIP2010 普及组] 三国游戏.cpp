#include<bits/stdc++.h>
using namespace std;
int arr[501][501];
int N;
int main(){
	cin >>N;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			int tmp;
			scanf("%d",&tmp);
			arr[i][j]=tmp;
			arr[j][i]=tmp;
		}
	}
	int second=0,max=0,MAX=0;
	for(int i=1;i<=N;i++){
		max=0;MAX=0;
		for(int j=1;j<=N;j++){
			if(arr[i][j]>max){
				max=arr[i][j];
			}
		}
		for(int j=1;j<=N;j++){
			if(arr[i][j]<max&&arr[i][j]>second){
				second=arr[i][j];
			}
		}
		if(second>MAX){
			MAX=second;
		}
	}
	cout <<1<<endl<<MAX;
	return 0;
}