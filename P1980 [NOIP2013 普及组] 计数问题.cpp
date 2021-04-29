#include<bits/stdc++.h>
using namespace std;
int behalf(int* list,int i){
	int sum=0;
	for(int j=i-1;j>=0;j--){
		sum*=10;
		sum+=list[j];
	}
	return sum+1;
}
int ABS(int n){
	if(n>0) return n;
	return 0;
}
int main(){
	int list[8];
	int val[8]={0,1,20,300,4000,50000,600000,7000000};
	int times[8]={1,10,100,1000,10000,100000,1000000,10000000};
	int n,i=0,k=0;
	int number=0;
	cin >>n>>k;
	int N=n;
	while(n){
		list[i]=n%10;
		n/=10;
		i++;
	}
	n=N;
	int m=1;
	for(int j=0;j<i;j++){
		if(k){//·ÇÁã
			number+=val[j]*list[j];
			if(k==list[j]){
				number+=behalf(list,j);
			}
			else if(k<list[j]){
				number+=times[j];
			}
		}
		else{//0
			int a=n/(m*10);int b=(n/m)%10;int c=n%m;
			if(b){
				number+=(a*m);
			}
			else{
				number+=(ABS(a-1)*m+c+1);
			}
			m*=10;
		}
	}
	cout << number;
	return 0;
}