#include<bits/stdc++.h>
using namespace std;
long long sum[50002];//ǰ׺������
int main(){
	int n;cin >>n;int tmp;
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		sum[i]=sum[i-1]+tmp;
	}
	for(int i=n;i>0;i--){//���䳤��
		for(int j=1;j+i-1<=n;j++){//������ʼ��
			long long S=sum[j+i-1]-sum[j-1];
			if(S%7==0){
				cout <<i;
				return 0;
			}
		}
	}
	cout <<0;
	return 0;
}
//����O2�Ż�֮����ͨ��
/*
����˼·�����������д�ˡ���
���������������7ȡģ����0������ڼ���ǰ׺�������ʱ��ֱ�Ӷ�7ȡģ
��ô����������7������һ�����
����7������Ϊ0-6��ֱ��ö��ÿһ��ģ������
*/