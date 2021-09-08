#include<bits/stdc++.h>
using namespace std;
int p[200005];
int n;
int main(){
	int t;cin >>t;
	while(t--){
		int left,right;
		cin >>n >>left>>right;
		int num=abs(left-right)/2;
		for(int i=1;i<=left;i++){
			int tmp;
			cin >>tmp;
			p[tmp]++;
		}
		for(int i=1;i<=right;i++){
			int tmp;
			cin >>tmp;
			p[tmp]--;
		}
		if(left>right){
			int turn=0;//改变数字的个数
			int change=0;//改变左右的个数
			for(int i=1;i<=n;i++){
				if(p[i]<0)turn-=p[i];
				if(p[i]>0)change+=abs(p[i])/2;
			}
			if(change>num){
				cout <<turn+num<<endl;
			}
			else{
				cout <<turn+2*num-change<<endl;
			}
		}
		else{
			int turn=0;//改变数字的个数
			int change=0;//改变左右的个数
			for(int i=1;i<=n;i++){
				if(p[i]>0)turn+=p[i];
				if(p[i]<0)change+=abs(p[i])/2;
			}
			if(change>num){
				cout <<turn+num<<endl;
			}
			else{
				cout <<turn+2*num-change<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			p[i]=0;
		}
	}
	return 0;
}