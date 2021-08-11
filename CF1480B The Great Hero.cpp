#include<iostream>
using namespace std;
int A,B;
int n;
struct H{
	int a;
	int b;
};

H hom[200005];
inline long long hurt(int i){
	int time=(hom[i].b+A-1)/A;
	return (long long)time*hom[i].a;
}
int MAX=0;//最强攻击力
long long sum=0;//计算攻击力总和
int max_i;//最强攻击力下标
int main(){
	int t;cin >>t;
	while(t--){
		sum=0;MAX=0;
		cin >>A>>B>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&hom[i].a);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&hom[i].b);
		}
		for(int i=1;i<=n;i++){
			sum+=hurt(i);
			if(hom[i].a>MAX){
				MAX=hom[i].a;
				max_i=i;
			}
		}
		if(sum-MAX>=B){
			cout <<"NO"<<endl;
		}
		else{
			if(B-sum+MAX>=0){
				cout <<"YES"<<endl;
			}
			else{
				cout <<"NO"<<endl;
			}
		}
	}
	return 0;
}