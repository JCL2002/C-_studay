#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define Type int
#define order 0//0:����;1������
Type List[MAX];
Type Cache[MAX];
void conquer(int left,int mid,int right){//��
	int first_i=left,second_i=mid+1,cache_i=left;//��һ�飬�ڶ���,��������±�
	while(cache_i<=right){
		if(first_i<=mid){//��һ�黹�г�Ա
			if(second_i<=right){//�ڶ���Ҳ������
				if(order){//����
					if(List[first_i]>List[second_i]){
						Cache[cache_i]=List[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=List[second_i];
						second_i++;cache_i++;
					}
				}
				else{//����
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
			else{//��һ���г�Ա���ڶ���û��
				Cache[cache_i]=List[first_i];
				first_i++;cache_i++;
			}
		}
		else{//��һ��û�г�Ա���ڶ�����
			Cache[cache_i]=List[second_i];
			second_i++;cache_i++;
		}
	}
	//�ض�
	cache_i=left;
	while(cache_i<=right){
		List[cache_i]=Cache[cache_i];
		cache_i++;
	}
	return;
}
void divid(int left,int right){//��
	int mid=left+(right-left)/2;
	if(right-left>1){//��ǰ���䳬������Ԫ���������
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