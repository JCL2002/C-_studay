#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	int c;
	int id;
};
int n;
stu R[302];

bool cmp(stu a,stu b){
	if(a.score==b.score){
		if(a.c==b.c) return a.id<b.id;
		return a.c>b.c;
	}
	return a.score>b.score;
}

int main(){
	int a,b,c;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a>>b>>c;
		R[i].score=a+b+c;
		R[i].id=i;
		R[i].c=a;
	}
	sort(R+1,R+1+n,cmp);
	for(int i=1;i<6;i++){
		cout <<R[i].id<<" "<<R[i].score<<endl;
	}
	return 0;
}