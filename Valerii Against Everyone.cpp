#include<bits/stdc++.h>
using namespace std;
long long b[1005];
int n;

void kick(int x){//�ϲ�����
	n--;
	for(int i=x;i<=n;i++){
		b[i]=b[i+1];
	}
}

int log(int x){//��2Ϊ�ף�x�Ķ���
	int num=0;
	while(x/2){
		x/=2;
		num++;
	}
	return num;
}

int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			scanf("%lld",b+i);
		}
//		b[0]=-1;
//		int l=1;
//		bool flag=false;
//		for(int i=1;i<n;i++){
//			if(b[i+1]!=b[l]){
//				//��l��i��һ����ֵ1����
//				int len=i-l+1;//���䳤��
//				int val=b[l];//����ֵ
//				int ds=log(len);//����ֵ
//				for(int j=i+1;j<=n;j++){
//					if(b[j]>=val&&b[j]<=val+ds){
//						flag=true;
//						break;
//					}
//				}
//				l=i+1;
//			}
//			else{
//				continue;
//			}
//		}
//		if(flag){
//			cout <<"YES"<<endl;
//		}
//		else{
//			cout <<"NO"<<endl;
//		}
		//����˼·��ɨ�����䣬��������ڵĵ�ֵ���Ͱ����Ǻϲ�+1��ֱ��û�п��Ժϲ���Ϊֹ
//		while(true){//��������
//			bool flag=false;
//			for(int i=1;i<n;i++){
//				if(b[i]==b[i+1]){
//					flag=true;
//					b[i]++;
//					kick(i+1);
//				}
//			}
//			if(flag){
//				continue;
//			}
//			break;
//		}
		
		
//		for(int i=1;i<=n;i++) cout <<b[i]<<' ';
//		cout <<endl;
		bool exi=false;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[i]==b[j]){
					exi=true;
					break;
				}
			}
		}
		if(exi){
			cout <<"YES"<<endl;
		}
		else{
			cout <<"NO"<<endl;
		}
	}
	return 0;
}