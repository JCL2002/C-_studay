#include<bits/stdc++.h>
using namespace std;

int main(){
	int dp[30000];
	for(int j=0;j<30000;j++){
		dp[j]=0;
	}
	int val[24];
	int weight[24];
	int N,m,coust,w;
	cin >> N >> m;
	for(int j=0;j<m;j++){
		cin >> coust >>w;
		weight[j]=coust;
		val[j]=coust*w;
	}
	for(int i=0;i<m;i++){//01����
		for(int j=N;j>=0;j--){
			if(j>weight[i]){//��װ����ʱ
				dp[j]=max(dp[j],dp[j-weight[i]]+val[i]);//״̬ת�Ʒ���
			}		
		}
	}
	cout << dp[N];
	return 0;
}