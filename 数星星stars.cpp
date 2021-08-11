#include<bits/stdc++.h>
using namespace std;
int tree[32004];
int res[15005];
int n;
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int i){
	while(i<=32001){
		tree[i]++;
		i+=lowbit(i);
	}
}
inline int sum(int i){
	int res=0;
	while(i>0){
		res+=tree[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
	int x,y;
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		x++;
		res[sum(x)]++;
		add(x);
	}
	for(int i=0;i<n;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//int n,x,y;
//int tree[100001];
//int ans[100001];
//
//int lowbit(int x){
//	return x&(-x);
//}
//int sum(int x){
//	int s=0;
//	for(;x>0;x=x-lowbit(x)){
//		s+=tree[x];
//		}
//	return s;
//}
//void add(int x){
//	for(;x<=32001;x=x+lowbit(x)){
//		tree[x]++;
//		}
//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++){
//    	cin>>x>>y;
//    	x++;
//    	ans[sum(x)]++;
//    	add(x);
//    	}
//    for(int i=0;i<=n-1;i++){
//    	cout<<ans[i]<<endl;
//    	}
//	return 0;
//}
