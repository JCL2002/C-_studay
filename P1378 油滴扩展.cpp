#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979
int le,ri,up,dow,a,b,c,d;//长方形的上下左右边界
int N;
struct point{
	int x;
	int y;
	bool cover;
	double r;
};
point arr[8];

double dfs(int depth,int i){
	arr[i].cover=true;
	double r=10000;
	r=min(r,(double)min(abs(arr[i].y-up),abs(arr[i].y-dow)));
	r=min(r,(double)min(abs(arr[i].x-ri),abs(arr[i].x-le)));
	double distance=1000000;//当前节点与剩下已展开节点能达到的最小距离
	for(int j=1;j<=N;j++){
		if(j!=i){
			if(arr[j].cover){
				double k=sqrt((double)(arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
				if(k-arr[j].r>0){
					distance=min(distance,k-arr[j].r);
				}
				else{
					distance=0;
					break;
				}
			}
		}
	}
	r=min(r,distance);//求出当前节点r的值
	arr[i].r=r;
	if(depth==N){
		double sum=0;
		for(int j=1;j<=N;j++){
			sum+=pi*arr[j].r*arr[j].r;
		}
		arr[i].cover=false;
		arr[i].r=0.0;
		return sum;
	}
	distance=0;//统计最大
	for(int j=1;j<=N;j++){
		if(j!=i&&arr[j].cover==false){
			distance=max(distance,dfs(depth+1,j));
		}
	}
	arr[i].cover=false;
	arr[i].r=0.0;
	return distance;
}

int main(){
	cin >>N;
	cin >>a>>b>>c>>d;
	le=min(a,c);ri=max(a,c);
	up=max(b,d);
	dow=min(b,d);
	for(int i=1;i<=N;i++){
		cin >>arr[i].x>>arr[i].y;
		arr[i].cover=false;
		arr[i].r=0.0;
	}
	double sum=0;
	for(int i=1;i<=N;i++){
		sum=max(sum,dfs(1,i));
	}
	if(sum-(int)sum>=0.5){
		cout <<(up-dow)*(ri-le)-(int)sum-1;
	}
	else{
		cout << (up-dow)*(ri-le)-(int)sum;
	}
	return 0;
}