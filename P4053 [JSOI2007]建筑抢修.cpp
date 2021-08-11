#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>>q;
int n,t,ans;
struct b{
	int f;//修复用时
	int t;//耐久度
};
b buil[150005];
bool cmp(b a,b c){
	return a.t<c.t;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&buil[i].f,&buil[i].t);
	}
	sort(buil+1,buil+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(t+buil[i].f>buil[i].t){//必须做出取舍
			if(q.top()>buil[i].f){
				t-=q.top();
				q.pop();
				t+=buil[i].f;
				q.push(buil[i].f);
			}
		}
		else{//继续
			t+=buil[i].f;
			q.push(buil[i].f);
			ans++;
		}
	}
	cout <<ans;
	return 0;
}