#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int g,l,n;
	while(true){
		cin >>g>>l>>n;
		if(g==0&&l==0&&n==0)break;
		priority_queue<int,vector<int>> L;//大根堆
		priority_queue<int,vector<int>,greater<int>> G;//小根堆
		long long sum=0;
		for(int i=1;i<=n;i++){
			int t;scanf("%d",&t);
			sum+=t;
			if(i<=l){//最小值维护
				L.push(t);
			}
			else{
				if(t<L.top()){
					L.pop();
					L.push(t);
				}
			}
			if(i<=g){//最大值维护
				G.push(t);
			}
			else{
				if(t>G.top()){
					G.pop();
					G.push(t);
				}
			}
		}
		while(!L.empty()){
			sum-=L.top();
			L.pop();
		}
		while(!G.empty()){
			sum-=G.top();
			G.pop();
		}
		printf("%.6f\n",(double)sum/(n-l-g));
	}
	return 0;
}