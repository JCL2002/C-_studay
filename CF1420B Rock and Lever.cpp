#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	int n;
	unsigned int a[100001];
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){//¼��
			scanf("%d",a+j);
		}
		unsigned long long total=0;
		for(int j=31;j>=0;j--){
			int number=0;
			for(int k=0;k<n;k++){
				if(a[k]&(1<<j)){//��鵱ǰλ�Ƿ�Ϊ1
					number++;
					for(int l=31;l>j;l--){//����Ƿ�Ϊ���λ
						if(a[k]&(1<<l)){//�����ǰλ֮ǰ��1������������
							number--;
							break;
						}
					}
				}
			}
			total+=(long long)number*(number-1)/2;
		}
		cout <<total<<endl;
	}
	return 0;
}