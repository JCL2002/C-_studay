#include<iostream>
using namespace std;
#define MAX 101
#define Type int
#define order 0//0:升序;1：降序
Type Cache[MAX];
int w[101];
void conquer(int left,int mid,int right){//治
	int first_i=left,second_i=mid+1,cache_i=left;//第一组，第二组,缓冲组的下标
	while(cache_i<=right){
		if(first_i<=mid){//第一组还有成员
			if(second_i<=right){//第二组也有数据
				if(order){//降序
					if(w[first_i]>w[second_i]){
						Cache[cache_i]=w[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=w[second_i];
						second_i++;cache_i++;
					}
				}
				else{//升序
					if(w[first_i]<w[second_i]){
						Cache[cache_i]=w[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=w[second_i];
						second_i++;cache_i++;
					}
				}
			}
			else{//第一组有成员，第二组没有
				Cache[cache_i]=w[first_i];
				first_i++;cache_i++;
			}
		}
		else{//第一组没有成员，第二组有
			Cache[cache_i]=w[second_i];
			second_i++;cache_i++;
		}
	}
	//回读
	cache_i=left;
	while(cache_i<=right){
		w[cache_i]=Cache[cache_i];
		cache_i++;
	}
	return;
}
void divid(int left,int right){//分
	int mid=left+(right-left)/2;
	if(right-left>1){//当前区间超过两个元素则继续分
		divid(left,mid);
		divid(mid+1,right);
	}
	conquer(left,mid,right);
	return;
}

int main(){
	int t;
	cin >>t;
	int n,x;
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&x);
		for(int j=0;j<n;j++){
			scanf("%d",w+j);
		}
		divid(0,n-1);//倒序排序
		int sum=0;bool flag=true;
		for(int j=0;j<n;j++){
			sum+=w[j];
			if(sum==x){//可能炸
				//检查后面有没有与当前元素不同的元素
				flag=false;
				for(int k=j+1;k<n;k++){
					if(w[k]!=w[j]){
						flag=true;
						int swap;
						swap=w[k];
						w[k]=w[j];
						w[j]=swap;
						break;
					}
				}
			}
		}
		if(flag){
			printf("YES\n");
			for(int j=0;j<n;j++){
				printf("%d",w[j]);
				if(j!=n-1){
					printf(" ");
				}
			}
			printf("\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}