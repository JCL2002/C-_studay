#include<bits/stdc++.h>
using namespace std;
int n,m,x,arr[100005];
struct node
{
	int idx,w;
	node(){idx = 0 , w = 0;}
	node(int IDX,int W){idx = IDX , w = W;}
	bool operator < (const node &oth) const { return w > oth.w; }
}smr;
priority_queue<node> q;
int flag[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		cin >>n>>m>>x;
		for(int i=1;i<=n;i++) cin >>arr[i];
		for(int i=1;i<=m;i++) q.push(node(i , 0));
		for(int i=1;i<=n;i++)
		{
			smr=q.top();q.pop();
			flag[i]=smr.idx;
			smr.w +=arr[i];
			q.push(smr);
		}
		while(!q.empty())q.pop();
		cout <<"YES"<<endl;
		for(int i=1;i<=n;i++) printf("%d ",flag[i]);
		cout <<endl;
	}
	return 0;
}