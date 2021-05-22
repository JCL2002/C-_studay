#include<bits/stdc++.h>
using namespace std;
struct AR{
	bool color;//false代表红色，true代表蓝色
	int val;//价值
};
AR arr[1000001];
struct Node{
	bool choose;//是否被选中
	bool color;//颜色,红色为false
	int val;//被选中珍珠的价值
	int max_of_b;//蓝色最大值
};
Node Link[1000001]={false,false,0,0};
int main(){
	int t,n,m;
	cin >>t;
	for(int i=0;i<t;i++){
		cin >>n>>m;
		//1的特判
		for(int j=0;j<n;j++){//价值录入
			for(int k=0;k<m;k++){
				scanf("%d",&arr[j*m+k].val);
			}
		}
		for(int j=0;j<t;j++){
			for(int k=0;k<m;k++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp){
					arr[j*m+k].color=true;
				}
				else{
					arr[j*m+k].color=false;
				}
			}
		}
		//贪心：只要当前被选中最大的哪个是蓝色，一定选
		for(int j=0;j<n;j++){
			//找备选中的最大值
			int max_i=0,max=arr[j*m].val;
			for(int k=1;k<m;k++){
				if(arr[j*m+k].val>max){
					max=arr[j*m+k].val;
					max_i=k;
				}
			}
			//判断最大的是不是蓝色
			if(arr[max_i].color){
				Link[j].choose=true;
				Link[j].color=true;
				Link[j].val=max;
			}
			else{
				Link[j].choose=false;
				Link[j].color=false;
				Link[j].val=max;
			}
		}
		//贪心：只要被两个蓝色夹住的最大值为红色的也一定选中
		for(int j=0;j<n;j++){
			//首尾特判
			if(j==0){
				if(Link[1].color){
					Link[j].choose=true;
				}
			}
			else if(j==n-1){
				if(Link[j-1].color){
					Link[j].choose=true;
				}
			}
			//其余情况判断相邻的两个
			else if(!Link[j].color){
				if(Link[j-1].color&&Link[j+1].color){
					Link[j].choose=true;
				}
			}
		}
		//找没被选中的蓝色的最大值，进行动态规划
		for(int j=0;j<n;j++){
			int max=-1;//不知道第一个是不是蓝色
			for(int k=0;k<m;k++){
				if(arr[j*m+k].color){
					if(arr[j*m+k].val>max){
						max=arr[j*m+k].val;
					}
				}
			}
			Link[j].max_of_b=max;
		}
		//动态规划
		for(int j=1;j<n;j++){
			if(Link[j].choose==false){
				if(Link[j-1].color){//上一个为蓝，直接选
					Link[j].choose=true;
				}
				else if(Link[j].val+Link[j-1].max_of_b>Link[j].max_of_b+Link[j-1].val){
					Link[j-1].color=true;
					Link[j].choose=true;
				}
			}
		}
		long long sum=0;
		for(int j=0;j<n;j++){
			if(Link[j].color){
				sum+=(long long)Link[j].val;
			}
			else{
				sum+=(long long)Link[j].max_of_b;
			}
		}
		cout <<sum<<endl;
	}
	return 0;
}