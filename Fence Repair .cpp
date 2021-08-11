#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		int a;
		cin >>a;
		q.push(a);
	}
	long long sum=0;
	while(true){
		int min_a=q.top();q.pop();
		sum+=min_a;
		if(q.empty())break;
		int min_b=q.top();q.pop();
		sum+=min_b;
		if(q.empty())break;
		q.push(min_a+min_b);
	}
	cout <<sum;
	return 0;
}