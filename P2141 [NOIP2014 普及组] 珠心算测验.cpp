#include<bits/stdc++.h>
using namespace std;
int number=0;
int ori=200000;
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void A(int* list,int left,int right,int depth){
	if(depth==3){
		if(list[0]==(list[1]+list[2])){
			if(list[0]!=ori){
				ori=list[0];
				number++;
			}
		}
		return;
	}
	for(int j=left;j<=right;j++){
		swap(list+left,list+j);
		A(list,left+1,right,depth+1);
		swap(list+j,list+left);
	}
}
int main(){
	int n;
	cin >>n;
	int* list;
	list=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		cin >>list[i];
	}
	A(list,0,n-1,0);
	cout << number;
	return 0;
}