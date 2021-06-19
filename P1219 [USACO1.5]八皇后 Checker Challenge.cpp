#include<bits/stdc++.h>
using namespace std;
int times=0;
int n;
bool occ[15][15];
int Rand[15];
void dfs(int i,int depth){
	occ[depth][i]=true;//标记占用
//	cout <<"深度："<<depth<<" 位置："<<i<<" 该列没有被占用且不在主副对角线上"<<endl;
	Rand[depth]=i;
	if(depth==n){
		times++;
		if(times<=3){
			for(int j=1;j<=n;j++){
				printf("%d",Rand[j]);
				if(j<n){
					printf(" ");
				}
			}
			printf("\n");
		}
		occ[depth][i]=false;//占用解除
		return ;
	}
	
	for(int j=1;j<=n;j++){
		if(true){//不在主副对角线上
			bool flag=true;
			for(int k=1;k<=n;k++){
				if(occ[k][j]){//该列被占用
				flag=false;
				break;
				}
			}
			if(flag){
				//检查与主副对角线平行的有无占用
				int ur,ul;
				ur=min(depth,n-j);ul=min(depth,j);
				if(flag){
					for(int k=1;k<=ur;k++){
						if(occ[depth+1-k][j+k]){
							flag=false;
							break;
						}
					}
				}
				if(flag){
					for(int k=1;k<=ul;k++){
						if(occ[depth+1-k][j-k]){
							flag=false;
							break;
						}
					}
				}
			}
			if(flag){
				dfs(j,depth+1);
			}
		}
	}
	occ[depth][i]=false;//占用解除
}
int main(){
	cin>>n;
	//初始化occ数组
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			occ[i][j]=false;
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,1);
	}
	cout <<times;
}