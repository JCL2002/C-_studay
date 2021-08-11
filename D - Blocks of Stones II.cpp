#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(cin >>n){
		priority_queue<int,vector<int>,greater<int>>q;
		for(int i=1;i<=n;i++){
			int tmp;scanf("%d",&tmp);
			q.push(tmp);
		}
		int sum=0;
		while(1){
			if(q.empty())break;
			int a=q.top();q.pop();
			if(q.empty())break;
			int b=q.top();q.pop();
			sum+=(a+b);
			q.push(a+b);
		}
		cout <<sum<<endl;
	}
	return 0;
}