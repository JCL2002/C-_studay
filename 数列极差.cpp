#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>G;//求最大
priority_queue<int,vector<int>>L;//求最小
int main(){
	int n;
	while(true){
	
	cin >>n;
	if(n==0)break;
	for(int i=0;i<n;i++){
		int t;scanf("%d",&t);
		G.push(t);
		L.push(t);
	}
	int min,max;
	while(true){
		max=G.top();G.pop();
		if(G.empty())break;
		max*=G.top();G.pop();
		max++;
		if(G.empty())break;
		G.push(max);
	}
	while(true){
		min=L.top();L.pop();
		if(L.empty())break;
		min*=L.top();L.pop();
		min++;
		if(L.empty())break;
		L.push(min);
	}
	cout <<max-min<<endl;
}
	return 0;
}