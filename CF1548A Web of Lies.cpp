#include<bits/stdc++.h>
using namespace std;
int arr[200005];//头上有几座大山
int n,m,q;
int main(){
	cin >> n >>m;
	int num=n;
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		int mmin=min(u,v);
		if(arr[mmin]==0) num--;
		arr[mmin]++;
	}
	cin >> q;
	for(int i=0;i<q;i++){
		int a,u,v;
		scanf("%d",&a);
		if(a==3){
			printf("%d\n",num);
		}
		else if(a==2){//删除
			scanf("%d %d",&u,&v);
			arr[min(u,v)]--;
			if(arr[min(u,v)]==0)num++;
		}
		else{//插入
			scanf("%d %d",&u,&v);
			if(arr[min(u,v)]==0) num--;
			arr[min(u,v)]++;
		}
	}
	return 0;
}