#include<iostream>
using namespace std;
int n;
int Q[200005];
bool used[200005];
int max_next[200005];
void init(){
	for(int i=1;i<=n;i++) used[i]=0;
}
int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>Q[i];
			if(Q[i]!=Q[i-1]) used[Q[i]]=1;
		}
		for(int i=2;i<=n;i++){
			max_next[i]=i-1;
		}
		int min=1;
		int max=Q[1]-1;
		for(int i=1;i<=n;i++){
			if(!used[i]){
				min=i;
				break;
			}
		}
		//打印最小字典序
		for(int i=1;i<=n;i++){
			if(Q[i]!=Q[i-1]) cout <<Q[i]<<" ";
			else{
				for(int j=min;j<=n;j++){
					if(!used[j]){
						cout <<j<<" ";
						min=j+1;
						break;
					}
				}
			}
		}
		cout <<endl;
		//打印最大字典序
		for(int i=1;i<=n;i++){
			if(Q[i]!=Q[i-1]){
				 cout <<Q[i]<<" ";
				 max=Q[i]-1;
			}
			else{
				int cpy=max;
				while(used[max])max=max_next[max];
				cout <<max<<" ";
				used[max]=1;
				max--;
				max_next[cpy]=max;
			}
		}
		cout <<endl;
		init();
	}
	return 0;
}