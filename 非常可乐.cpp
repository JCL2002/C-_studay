#include<iostream>
#include<algorithm>
using namespace std;
bool Find=false;
int S,N,M;
int stat[102][102][102];//S、N、M每个的状态
void init(){
	for(int i=0;i<102;i++){
		for(int j=0;j<102;j++){
			for(int k=0;k<102;k++){
				stat[i][j][k]=false;
			}
		}
	}
}
void dfs(int s,int n,int m,int depth){
	if(stat[s][n][m]) {
		if(depth<stat[s][n][m]){
			stat[s][n][m]=depth;
		}
		else{
			return ;
		}
	}
	stat[s][n][m]=depth;
	if(s==0){
		if(n==m){
			Find=true;
			return ;
		}
	}
	else{//s有
		int n_r=N-n;
		if(n_r){//n有空
			dfs(s-min(s,n_r),n+min(s,n_r),m,depth+1);
		}
		int m_r=M-m;
		if(m_r){//m有空
			dfs(s-min(s,m_r),n,m+min(s,m_r),depth+1);
		}
	}
	if(n==0){
		if(s==m){
			Find=true;
			return ;
		}
	}
	else{//n有
		int s_r=S-s;
		int m_r=M-m;
		if(s_r) dfs(s+min(n,s_r),n-min(n,s_r),m,depth+1);
		if(m_r) dfs(s,n-min(n,m_r),m+min(n,m_r),depth+1);
	}
	if(m==0){
		if(s==n){
			Find=true;
			return ;
		}
	}
	else{//m有
		int s_r=S-s;
		int n_r=N-n;
		if(s_r) dfs(s+min(m,s_r),n,m-min(m,s_r),depth+1);
		if(n_r) dfs(s,n+min(m,n_r),m-min(m,n_r),depth+1);
	}
}

int main(){
	while(true){
		cin >>S>>N>>M;
		if(S==0)break;
		if(S%2){
			cout <<"NO"<<endl;//奇数必不能
			Find=false;
			continue;
		}
		dfs(S,0,0,1);
		if(Find){
			Find=false;
			//-----------------------------------
			int MIN=10000000;
			if(stat[S/2][S/2][0])MIN=min(MIN,stat[S/2][S/2][0]);
			if(stat[S/2][0][S/2])MIN=min(MIN,stat[S/2][0][S/2]);
			if(stat[0][S/2][S/2])MIN=min(MIN,stat[0][S/2][S/2]);
			cout <<MIN-1<<endl;
			init();
		}
		else{
			cout <<"NO"<<endl;
			init();
		}
	}
	return 0;
}