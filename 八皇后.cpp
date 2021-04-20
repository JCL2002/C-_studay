#include<bits/stdc++.h>
using namespace std;
int ways=0;
int H[16]={0};//储存每个皇后的列
int n;
void dfs(int l,int H[8]){
	if(l==n){
		ways++;//最后一行肯定只有一种方式安放
		return;
	}
	int i,j;
	char flag;//可安放标志
	char dig;//对角线占用标志
	for(i=0;i<n;i++){
		//检查第i列可否安放皇后
		flag='t';dig='f';
		for(j=0;j<l;j++){
			if(H[j]==i){//如果被占用
				flag='f';
				break;
			}
			//检测对角线是否占用
			if(abs(l-j)==abs(H[j]-i)){
				dig='t';
			}
		}
		if(flag=='t'&&dig=='f'){
			H[l]=i;
			dfs(l+1,H);
		}
	}
}

int main(){
	cin >> n;
	dfs(0,H);
	cout << ways;
	return 0;
}