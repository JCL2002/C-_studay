#include<bits/stdc++.h>
using namespace std;
const int N=12;
int arr[N][N];
int n;
int main(){
	cin >>n;
	arr[0][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=arr[i-1][j]+arr[i][j-1];
		}
	}
	cout <<arr[n][n];
	return 0;
}