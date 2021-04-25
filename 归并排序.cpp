#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define Type int
#define order 0//0:升序;1：降序
Type List[MAX];
Type Cache[MAX];
void conquer(int left,int mid,int right){//治
	int first_i=left,second_i=mid+1,cache_i=left;//第一组，第二组,缓冲组的下标
	while(cache_i<=right){
		if(first_i<=mid){//第一组还有成员
			if(second_i<=right){//第二组也有数据
				if(order){//降序
					if(List[first_i]>List[second_i]){
						Cache[cache_i]=List[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=List[second_i];
						second_i++;cache_i++;
					}
				}
				else{//升序
					if(List[first_i]<List[second_i]){
						Cache[cache_i]=List[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=List[second_i];
						second_i++;cache_i++;
					}
				}
			}
			else{//第一组有成员，第二组没有
				Cache[cache_i]=List[first_i];
				first_i++;cache_i++;
			}
		}
		else{//第一组没有成员，第二组有
			Cache[cache_i]=List[second_i];
			second_i++;cache_i++;
		}
	}
	//回读
	cache_i=left;
	while(cache_i<=right){
		List[cache_i]=Cache[cache_i];
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
	int number,i;
	int time_1,time_2;
	srand(time(NULL));
	cin >> number;
	for(i=0;i<number;i++){
		List[i]=rand();
	}
	time_1=time(NULL);
	divid(0,number-1);
	time_2=time(NULL);
	cout <<time_2-time_1;
	return 0;
}