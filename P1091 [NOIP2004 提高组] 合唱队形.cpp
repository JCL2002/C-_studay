#include<bits/stdc++.h>
using namespace std;
int n;
int high[103];//���
int up[103];//��������
int down[103];//�½�����
int ans[103];//��iΪ�ֽ��߶Ͽ�����ߵ�����������к��ұߵ�����½�����
void init(){
	for(int i=1;i<=n;i++) up[i]=down[i]=0;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++) cin>>high[i];
	int mmax=0;
	for(int i=1;i<=n;i++){
		int num_up=0,num_down=0;
		for(int j=1;j<=i;j++){
			if(high[j]>up[num_up]) up[++num_up]=high[j];
			else{
				*lower_bound(up+1,up+1+num_up,high[j])=high[j];
			}
		}
		for(int j=n;j>=i;j--){
			if(high[j]>down[num_down]) down[++num_down]=high[j];
			else{
				*lower_bound(down+1,down+1+num_down,high[j])= high[j];
			}
		}
//		cout <<"up: "<<num_up<<"down: "<<num_down<<endl;
		mmax=max(mmax,num_up+num_down);
//		cout <<mmax<<endl;
	}
	cout <<n-mmax+1;
	return 0;
}