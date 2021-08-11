#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[108];
int bit_a[20];
int bit_b[20];
int turn(long long x,int* list){//转化长整型x
	int i=1;
	list[i]=x%10;
	while(x/10){
		x/=10;
		list[++i]=x%10;
	}
	return i;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",arr+i);
	}
	bool flag=false;
	for(int i=1;i<n;i++){
		int a=turn(arr[i],bit_a);
		int b=turn(arr[i+1],bit_b);
		if(a!=b)continue;
		if(a==1&&b==1){
			if(arr[i]){
				arr[i+1]=0;
				flag=1;
				break;
			}
			else{
				if(arr[i+1]!=9){
					flag=true;
					arr[i]=9;
				}
				else continue;
			}
		}
		if(bit_b[b]!=9){
			flag=true;
			bit_a[a]=9;
			//还原数据
			long long tmp=0;
			for(int j=a;j>0;j--){
				tmp*=10;
				tmp+=bit_a[j];
			}
			arr[i]=tmp;
			break;
		}
		else if(bit_a[a]!=1){
			flag=true;
			bit_b[b]=1;
			long long tmp=0;
			for(int j=b;j>0;j--){
				tmp*=10;
				tmp+=bit_b[j];
			}
			arr[i+1]=tmp;
			break;
		}
		else{//比较去掉第一位剩下的是不是前面的大于后面的
			long long be=0,af=0;
			for(int j=a-1;j>0;j--){
				be*=10;
				be+=bit_a[j];
			}
			for(int j=a-1;j>0;j--){
				af*=10;
				af+=bit_b[j];
			}
			if(be>af){
				bit_a[a]=9;
				flag=true;
				long long tmp=0;
				for(int j=a;j>0;j--){
					tmp*=10;
					tmp+=bit_a[j];
				}
				arr[i]=tmp;
				break;
			}
			else{
				continue;
			}
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			printf("%lld ",arr[i]);
		}
	}
	else cout <<"impossible"<<endl;
	return 0;
}