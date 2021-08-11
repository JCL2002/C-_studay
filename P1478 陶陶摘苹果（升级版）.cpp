#include<bits/stdc++.h>
using namespace std;
int n,s;
int a,b;

struct apple{
	int x;
	int y;
};

apple arr[5002];
apple ava[5002];//能摘到的苹果

bool cmp(apple a,apple b){
	return a.y<b.y;
}

int main(){
	cin >>n>>s;
	cin >>a>>b;
	for(int i=1;i<=n;i++){
		cin >>arr[i].x>>arr[i].y;
	}
	int number=0;
	for(int i=1;i<=n;i++){
		if(a+b>=arr[i].x){
			ava[number++]=arr[i];
		}
	}
	sort(ava,ava+number,cmp);
	int res=0,i=0;
	while(s>0&&i<number){
		if(ava[i].y<=s){
			res++;
			s-=ava[i].y;
		}
		i++;
	}
	cout <<res;
}