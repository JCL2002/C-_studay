#include<iostream>
using namespace std;
//��������˼·��
//����Ϣ�ֻص��Լ�����ʱ��˵���γ���һ���ջ�������ÿһ���ڵ�ǰ�����νӵ��Լ���Ϣ���辭���Ĳ�����ȣ��������һ����յ��Լ���Ϣ�Ĳ��裬���ǵ�ǰ������Ĵ�
//�п���������Ϣ�޷��ص��������������dfs�Ľ����ж������ǣ���ǰ���Ѿ��߹�һ��
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