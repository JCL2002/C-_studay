#include<bits/stdc++.h>
using namespace std;
int arr[150];//��Ҫ�£�nû����ô��
int n;int c;
int dfs(int v,int i){
	if(i==1){
		if(v>=arr[1]){//��������
			return arr[1];
		}
		return 0;
	}
	else if(i<3){//��С��3ʱ�����װ�Ϸ�����ã�������ʵʵ��
		if(v>=arr[i]){
			return max(arr[i]+dfs(v-arr[i],i-1),dfs(v,i-1));
		}
		return dfs(v,i-1);
	}
	else{
		if(v>=arr[i]){//��ʼ����
			return max(arr[i]+dfs(v-arr[i],i-1),arr[i-1]+dfs(v-arr[i-1],i-2));
		}
		else{
			return dfs(v,i-1);
		}
	}
}
int main(){
	cin >>n>>c;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	cout <<dfs(c,n);
	return 0;
}