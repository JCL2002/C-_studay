#include<iostream>
#include<algorithm>
using namespace std;
int n;
int m;
int fa[1000006];
void init(){
	for(int i=0;i<=m;i++){
		fa[i]=i;
	}
}
int Find(int x){
	if(x!=fa[x]){
		fa[x]=Find(fa[x]);
	}
	return fa[x];
}
void Union(int a,int b){
	int ra=Find(a),rb=Find(b);
	if(ra==rb)return;
	fa[ra]=rb;
}
struct op{//��¼�����Ľṹ�壬�������
	int i;
	int j;
	bool e;
};
op operation[1000006];
int app[2000012];//��¼���ֵ�i��j
int bfind(int x){//��ӳ����ж��ֲ���
	int l=0;int r=m-1;int mid=(l+r)/2;
	while(l<r){
		if(r-l==1){
			if(app[l]==x){
				return l;
			}
			else{
				return r;
			}//�����ܲ�ƥ��
		}
		else{
			mid=(l+r)/2;
			if(app[mid]==x){
				return mid;
			}
			else if(app[mid]>x){
				if(app[mid-1]==x) return mid-1;
				r=mid-1;
			}
			else{
				if(app[mid+1]==x) return mid+1;
				l=mid+1;
			}
		}
	}
	return -1;//�Ҳ����ǲ����ܵ�
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&operation[i].i,&operation[i].j,&operation[i].e);//���Ӿ�����Ϣ
			app[2*i-1]=operation[i].i;
			app[2*i]=operation[i].j;
		}
		sort(app+1,app+1+2*n);
		m=0;//Ҫӳ��ĸ���
		int before=-1;
		for(int i=1;i<=2*n;i++){//Ԫ��ȥ��
			if(app[i]!=before){
				app[m++]=app[i];
				before=app[i];
			}
		}
		init();
		//˼·��һ�߶��ֲ��ң�һ��Union
		for(int i=1;i<=n;i++){
			if(operation[i].e){
				Union(bfind(operation[i].i),bfind(operation[i].j));
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(operation[i].e==0){
				if(Find(bfind(operation[i].i))==Find(bfind(operation[i].j))){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			cout <<"YES"<<endl;
		}
		else{
			cout <<"NO"<<endl;
		}
		
	}
	return 0;
}