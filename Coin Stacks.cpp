#include<bits/stdc++.h>
using namespace std;
struct sta{
	int x;
	int i;
	bool operator <(const sta& b)const {return x<b.x;}
};
priority_queue<sta,vector<sta>>q;

struct order{
	int a;
	int b;
};
vector<order>o;
int main(){
	int n,sum=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		int tmp;
		cin >>tmp;
		sum+=tmp;
		if(tmp>0)
		q.push(sta{tmp,i});
	}
	if(sum%2){
		cout <<"no";
		return 0;
	}
	while(1){
		if(q.empty()){//刚好拿完了
			cout <<"yes"<<endl;
			for(int i=0;i<(int)o.size();i++){
				printf("%d %d\n",o[i].a,o[i].b);
			}
			return 0;
			break;
		}
		sta a=q.top();q.pop();
		if(q.empty()){//剩下单独的堆,失败
			cout <<"no";
			return 0;
		}
		sta b=q.top();q.pop();
		o.push_back(order{a.i,b.i});
		a.x--;b.x--;
//		cout <<a.x<<"  "<<b.x<<endl;
		if(a.x) q.push(a);
		if(b.x) q.push(b);
	}
	return 0;
}