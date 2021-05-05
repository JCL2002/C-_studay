#include<iostream>
using namespace std;
#define MAX 101
#define Type int
#define order 0//0:����;1������
Type Cache[MAX];
int w[101];
void conquer(int left,int mid,int right){//��
	int first_i=left,second_i=mid+1,cache_i=left;//��һ�飬�ڶ���,��������±�
	while(cache_i<=right){
		if(first_i<=mid){//��һ�黹�г�Ա
			if(second_i<=right){//�ڶ���Ҳ������
				if(order){//����
					if(w[first_i]>w[second_i]){
						Cache[cache_i]=w[first_i];
						first_i++;cache_i++;
					}
					else{
						Cache[cache_i]=w[second_i];
						second_i++;cache_i++;
					}
				}
				else{//����
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
			else{//��һ���г�Ա���ڶ���û��
				Cache[cache_i]=w[first_i];
				first_i++;cache_i++;
			}
		}
		else{//��һ��û�г�Ա���ڶ�����
			Cache[cache_i]=w[second_i];
			second_i++;cache_i++;
		}
	}
	//�ض�
	cache_i=left;
	while(cache_i<=right){
		w[cache_i]=Cache[cache_i];
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
	int t;
	cin >>t;
	int n,x;
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&x);
		for(int j=0;j<n;j++){
			scanf("%d",w+j);
		}
		divid(0,n-1);//��������
		int sum=0;bool flag=true;
		for(int j=0;j<n;j++){
			sum+=w[j];
			if(sum==x){//����ը
				//��������û���뵱ǰԪ�ز�ͬ��Ԫ��
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