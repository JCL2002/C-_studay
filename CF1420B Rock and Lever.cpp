#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t;
	int n;
	unsigned int a[100001];
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){//录入
			scanf("%d",a+j);
		}
		unsigned long long total=0;
		for(int j=31;j>=0;j--){
			int number=0;
			for(int k=0;k<n;k++){
				if(a[k]&(1<<j)){//检查当前位是否为1
					number++;
					for(int l=31;l>j;l--){//检查是否为最高位
						if(a[k]&(1<<l)){//如果当前位之前有1，此数不作数
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