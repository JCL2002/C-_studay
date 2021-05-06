#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ShuZu[100][100],QianZhui[100][100];
	cin >>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >>ShuZu[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0||j==0){//第一行或者第一列
				if(i==0&&j==0){//起点
					QianZhui[0][0]=ShuZu[0][0];
				}
				else if(i==0){//第一行
					QianZhui[0][j]=QianZhui[0][j-1]+ShuZu[0][j];
				}
				else{//第一列
					QianZhui[i][0]=QianZhui[i-1][0]+ShuZu[i][0];
				}
			}
			else{
				QianZhui[i][j]=ShuZu[i][j]+QianZhui[i-1][j]+QianZhui[i][j-1]-QianZhui[i-1][j-1];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout <<QianZhui[i][j]<<"  ";
		}
		cout <<endl;
	}
}