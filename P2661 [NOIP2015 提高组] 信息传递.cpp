#include<iostream>
using namespace std;
//基本解题思路：
//当信息轮回到自己哪里时，说明形成了一个闭环，环上每一个节点前后两次接到自己信息所需经历的步骤相等，因此任意一点接收到自己信息的步骤，就是当前这个环的答案
//有可能遇到信息无法回到自身的情况，因此dfs的结束判定条件是：当前点已经走过一次
int Next[200006];
int ans[200006];
int dep[200006];
int n;
int dfs(int i,int depth){
	if(ans[i])return ans[i];
	if(dep[i]){
		ans[i]=depth-dep[i];
		return ans[i];
	}
	dep[i]=depth;
	return ans[i]=dfs(Next[i],depth+1);
}

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d",Next+i);
	}
	for(int i=1;i<=n;i++){
		if(dep[i]==0) dfs(i,i);
	}
	int MIN=200006;
	for(int i=1;i<=n;i++){
		MIN=min(MIN,ans[i]);
	}
	cout <<MIN;
	return 0;
}