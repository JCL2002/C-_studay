#include<bits/stdc++.h>
using namespace std;
int ways=0;
int H[16]={0};//����ÿ���ʺ����
int n;
void dfs(int l,int H[8]){
	if(l==n){
		ways++;//���һ�п϶�ֻ��һ�ַ�ʽ����
		return;
	}
	int i,j;
	char flag;//�ɰ��ű�־
	char dig;//�Խ���ռ�ñ�־
	for(i=0;i<n;i++){
		//����i�пɷ񰲷Żʺ�
		flag='t';dig='f';
		for(j=0;j<l;j++){
			if(H[j]==i){//�����ռ��
				flag='f';
				break;
			}
			//���Խ����Ƿ�ռ��
			if(abs(l-j)==abs(H[j]-i)){
				dig='t';
			}
		}
		if(flag=='t'&&dig=='f'){
			H[l]=i;
			dfs(l+1,H);
		}
	}
}

int main(){
	cin >> n;
	dfs(0,H);
	cout << ways;
	return 0;
}