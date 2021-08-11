#include<bits/stdc++.h>
using namespace std;
struct s{
	long long z;//分子
	long long m;//分母
};
int station[1003];
int n;
double size(s& a){
	return (double)a.z/(double)a.m;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>station[i];
	}
	s left,right;
	right.z=10000000;
	right.m=1;
	left.z=0;
	left.m=1;
	for(int i=1;i<=n;i++){
		if(size(left)<(double)station[i]/i) {
			left.m=i;
			left.z=station[i];
		}
		if(size(right)>(double)(station[i]+1)/i){
			right.m=i;
			right.z=(station[i]+1);
		}
	}
	if((n+1)*right.z%right.m==0){
		//能够整除，则两者的首位数只差等于1
		if((n+1)*right.z/right.m==(n+1)*left.z/left.m+1){
			cout <<"unique"<<endl;
			cout <<(n+1)*left.z/left.m;
		}
		else{
			cout <<"not unique";
			return 0;
		}
	}
	else{
		//两者首位数只能相等
		if((n+1)*right.z/right.m==(n+1)*left.z/left.m){
			cout <<"unique"<<endl;
			cout <<(n+1)*left.z/left.m;
		}
		else{
			cout <<"not unique";
			return 0;
		}
	}
	return 0;
}