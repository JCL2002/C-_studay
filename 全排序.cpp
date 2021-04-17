#include<bits/stdc++.h>
using namespace std;

int List[20];

void swap(int begin,int end){
	int temp;
	temp=List[begin];
	List[begin]=List[end];
	List[end]=temp;
}
void QP(int begin,int end){
	int i;
	if(begin==end){
		for(i=0;i<=end;i++){
			printf("%d",List[i]);
		}
		printf("\n");
		return;
	}
	for(i=begin;i<=end;i++){
		swap(begin,i);
		QP(begin+1,end);
		swap(i,begin);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&List[i]);
	}
	QP(0,n-1);
	return 0;
}