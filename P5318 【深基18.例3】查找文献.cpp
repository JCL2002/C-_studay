#include<bits/stdc++.h>
using namespace std;
//�����ڽӱ��ͼ
int n,m;
vector<int>G[100005];
bool vis[100005];
void DFS(int out){
	if(vis[out])return;
	vis[out]=1;
	printf("%d ",out);
	for(int j=0;j<(int)G[out].size();j++){
		DFS(G[out][j]);
	}
}
int main(){
	cin >>n>>m;
	//n�ǲ���������m�����ӵ�����
	for(int i=1;i<=m;i++){//���ݵ�¼��
		int from,to;
		scanf("%d %d",&from,&to);
		G[from].push_back(to);
	}
	for(int i=1;i<=n;i++){//���ڽӱ�����
		sort(G[i].begin(),G[i].end());
	}
	//DFS����
	DFS(1);
	cout <<endl;
	//BFS����
	//��ʼ��
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	queue<int>zero;//���Ϊ0�Ľڵ�
	zero.push(1);//��1Ϊ���
	//��ʼBFS
	while(!zero.empty()){//BFS
		int out=zero.front();zero.pop();
		vis[out]=1;
		printf("%d ",out);
		//����������Ϊ0�ĵ�
		for(int i=0;i<(int)G[out].size();i++){
			if(vis[G[out][i]]==false){
				vis[G[out][i]]=true;
				zero.push(G[out][i]);
			}
		}
	}
	return 0;
}