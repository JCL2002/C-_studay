#include<bits/stdc++.h>
using namespace std;
const int N=1003;
bool arrive[N][N];
int a[N];//ÿ��Ҫͣ���ĳ�վ
int n,m;
int indeg[N];//���
int main(){
	cin >>n>>m;
	for(int i=0;i<m;i++){//����¼��
		scanf("%d",a);
		for(int i=1;i<=a[0];i++){
			scanf("%d",a+i);
		}
		//a[1]�����a[a[0]]���յ�
		//��ͼ-��˹ͼ
		int left=1;
		for(int i=a[1];i<=a[a[0]];i++){
			//ӦΪ��վ�ǵ���˳�������кõģ��ж�һ��վ���ǲ���Ҫͣ������Ҫ�������е�վ�㣬����Ҫ����һ��ͣ�������ԱȾͺ�
			if(a[left]==i){
				left++;
				continue;
			}
			else{
				//��a[1]��a[a[0]]�ĳ�վ�У�i�����վ��ͣ��˵������Ҫͣ���ĳ�վ�ļ�����ڵ�ǰ��վ
				for(int j=1;j<=a[0];j++){
					arrive[a[j]][i]=1;
				}
			}
		}
	}
	//��������
	//�������������
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arrive[j][i])indeg[i]++;
		}
	}
	queue<int>q;
	int depth=0;
	//���0��ȵ㣬���
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
		//�������0��ȶ���
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