#include<bits/stdc++.h>
using namespace std;
int times=0;
int n;
bool occ[15][15];
int Rand[15];
void dfs(int i,int depth){
	occ[depth][i]=true;//���ռ��
//	cout <<"��ȣ�"<<depth<<" λ�ã�"<<i<<" ����û�б�ռ���Ҳ��������Խ�����"<<endl;
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
		occ[depth][i]=false;//ռ�ý��
		return ;
	}
	
	for(int j=1;j<=n;j++){
		if(true){//���������Խ�����
			bool flag=true;
			for(int k=1;k<=n;k++){
				if(occ[k][j]){//���б�ռ��
				flag=false;
				break;
				}
			}
			if(flag){
				//����������Խ���ƽ�е�����ռ��
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
	occ[depth][i]=false;//ռ�ý��
}
int main(){
	cin>>n;
	//��ʼ��occ����
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