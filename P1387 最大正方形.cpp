#include <bits/stdc++.h>
using namespace std;
//��ά����ǰ׺��
int n,m;
int sum[102][102];
int main(){
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int tmp;
			scanf("%d",&tmp);
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+tmp;
		}
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int possible=sqrt(sum[i][j]);//�����ܵ��������ǵ�ǰ��sumֵ�����ţ��������б��������������
			possible=min(possible,min(i,j));//�����εĴ�С�����ܳ���i��j�е���Сֵ������Ϊ�˷�ֹ�±�Խ��
			for(int k=possible;k>0;k--){
				if(k*k==sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]){
					if(k>max){
						max=k;
						break;
					}
					else{
						break;
					}
				}
			}
		}
	}
	cout <<max;
	return 0;
}