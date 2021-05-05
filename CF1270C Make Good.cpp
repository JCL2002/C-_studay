#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >>t;
	unsigned long long a[100000];
	//注意a是long long类型的
	for(int i=0;i<t;i++){
		int n;scanf("%d",&n);
		for(int j=0;j<n;j++){//录入
			scanf("%lld",a+j);
		}
		int num[64];int carry;unsigned short I[64];carry=0;
		for(int j=0;j<64;j++){//num数组计算
			num[j]=0;//num数组初始化
			for(int k=0;k<n;k++){
				if(a[k]&((unsigned long long)1<<j)){
					num[j]++;
				}
			}
		}
		
		//完成I[0]的计算
		if(1&num[0]){
			I[0]=1;
		}
		else{
			I[0]=0;
		}
		num[0]+=I[0];carry=(carry+num[0])/2;
		//完成I[1-63]的计算
		for(int j=1;j<64;j++){
			if((num[j]+carry-num[j-1])&1){
				I[j]=1;
			}
			else{
				I[j]=0;
			}
			num[j]+=I[j];carry=(carry+num[j])/2;
		}
		//把I[]转化成unsigned long long
		unsigned long long result=0;
		for(int j=0;j<64;j++){
			result|=((unsigned long long)I[j]<<j);
		}
		if(result){
			printf("1\n%lld\n",result);
		}
		else{
			printf("0\n\n");
		}
	}
	return 0;
}