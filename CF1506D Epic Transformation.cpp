#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int> >q;
int num;
int times[200005];
int arr[200005];
int n;

int main(){
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++) cin >>arr[i];
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			if(arr[i]!=arr[i-1]) num++;
			times[num]++;
		}
//		cout <<endl;
//		for(int i=1;i<=num;i++) cout <<times[i]<<endl;
//		cout <<endl;
		for(int i=1;i<=num;i++) q.push(times[i]);
		while(!q.empty()){
			int a=q.top();
			q.pop();
			if(q.empty()){
				q.push(a);
				break;
			}
			int b=q.top();
			q.pop();
			if(a>1) q.push(a-1);
			if(b>1) q.push(b-1);
		}
		if(q.empty()) cout <<0<<endl;
		else{
			cout <<q.top()<<endl;
			q.pop();
		}
		for(int i=1;i<=num;i++)times[i]=0;
		num=0;
	}
	return 0;
}