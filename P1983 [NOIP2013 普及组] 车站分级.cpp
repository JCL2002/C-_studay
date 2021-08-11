#include<bits/stdc++.h>
using namespace std;
const int N=1003;
bool arrive[N][N];
int a[N];//每个要停车的车站
int n,m;
int indeg[N];//入度
int main(){
	cin >>n>>m;
	for(int i=0;i<m;i++){//数据录入
		scanf("%d",a);
		for(int i=1;i<=a[0];i++){
			scanf("%d",a+i);
		}
		//a[1]是起点a[a[0]]是终点
		//存图-哈斯图
		int left=1;
		for(int i=a[1];i<=a[a[0]];i++){
			//应为车站是单调顺序是排列好的，判断一个站点是不是要停车不需要遍历所有的站点，至于要和下一次停车点做对比就好
			if(a[left]==i){
				left++;
				continue;
			}
			else{
				//从a[1]到a[a[0]]的车站中，i这个车站不停，说明所有要停靠的车站的级别高于当前车站
				for(int j=1;j<=a[0];j++){
					arrive[a[j]][i]=1;
				}
			}
		}
	}
	//拓扑排序
	//计算各个点的入度
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arrive[j][i])indeg[i]++;
		}
	}
	queue<int>q;
	int depth=0;
	//检查0入度点，入队
	for(int i=1;i<=n;i++){
		if(!indeg[i]){
			q.push(i);
			indeg[i]=-1;
		}
	}
	while(!q.empty()){
		depth++;
		while(!q.empty()){
			int out=q.front();q.pop();
			for(int i=1;i<=n;i++){
				indeg[i]-=arrive[out][i];
			}
		}
		//检查所有0入度顶点
		for(int i=1;i<=n;i++){
			if(!indeg[i]){
				q.push(i);
				indeg[i]=-1;
			}
		}
	}
	cout <<depth;
	return 0;
}