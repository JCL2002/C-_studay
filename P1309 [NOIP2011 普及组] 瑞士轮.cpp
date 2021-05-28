#include<bits/stdc++.h>
using namespace std;
struct P{
	int id;
	int score;
	int ability;
};
P player[200002];
//归并排序
P cache[200002];
P W[100001];
P L[100001];
void conquer(int left,int mid,int right){
	//前区间段：[left,mid);后区间段[mid,right)
	int f=left;int s=mid;int c=f;
	while(f<mid||s<right){
		if(f<mid&&s<right){//两个区间段都没有读取完毕
			//判定条件
			if(player[f].score>player[s].score){
				cache[c++]=player[f++];
			}
			else if(player[f].score<player[s].score){
				cache[c++]=player[s++];
			}
			else{//当两者相等时
				if(player[f].id<player[s].id){
					cache[c++]=player[f++];
				}
				else{
					cache[c++]=player[s++];
				}
			}
		}
		else if(f<mid){
			cache[c++]=player[f++];
		}
		else{
			cache[c++]=player[s++];
		}
	}
	//数据回读
	for(int i=left;i<right;i++){
		player[i]=cache[i];
	}
}
void sort(int head,int end){
	//区间段：[head,end)
	int mid=(head+end)/2;
	if(end-head==1){
		return ;
	}
	sort(head,mid);sort(mid,end);
	conquer(head,mid,end);
}
int main(){
	int N,R,Q;
	cin >>N>>R>>Q;
	for(int i=1;i<=2*N;i++){
		scanf("%d",&player[i].score);
		player[i].id=i;
	}
	for(int i=1;i<=2*N;i++){
		scanf("%d",&player[i].ability);
	}
	sort(1,2*N+1);//第一遍顺序时杂乱无章的，必须进行排序
	for(int i=0;i<R;i++){
		int win=0,lose=0;
		for(int i=1;i<=N;i++){
			if(player[2*i-1].ability>player[2*i].ability){
				player[2*i-1].score++;
				W[win++]=player[2*i-1];L[lose++]=player[2*i];
			}
			else{
				player[2*i].score++;
				W[win++]=player[2*i];L[lose++]=player[2*i-1];
			}
		}
		int j=0,k=0,l=1;
		while(j<win||k<lose){//Winer和Loser队伍在本轮的序列时不变的，因此可以看作归并排序的两个子序列
			//他们可以在进行比赛的时候就顺便求解出来,每次排序的时间复杂度被从O(nlogn)压缩到O(n)
			if(j<win&&k<lose){
				if(W[j].score>L[k].score){
					player[l++]=W[j++];
				}
				else if(W[j].score<L[k].score){
					player[l++]=L[k++];
				}
				else{
					if(W[j].id<L[k].id){
						player[l++]=W[j++];
					}
					else{
						player[l++]=L[k++];
					}
				}
			}
			else if(j<win){
				player[l++]=W[j++];
			}
			else{
				player[l++]=L[k++];
			}
		}
	}
	cout <<player[Q].id;
	return 0;
}