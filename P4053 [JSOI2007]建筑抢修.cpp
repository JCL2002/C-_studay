#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>>q;
int n,t,ans;
struct b{
	int f;//�޸���ʱ
	int t;//�;ö�
};
b buil[150005];
bool cmp(b a,b c){
	return a.t<c.t;
}
int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&buil[i].f,&buil[i].t);
	}
	sort(buil+1,buil+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(t+buil[i].f>buil[i].t){//��������ȡ��
			if(q.top()>buil[i].f){
				t-=q.top();
				q.pop();
				t+=buil[i].f;
				q.push(buil[i].f);
			}
		}
		else{//����
			t+=buil[i].f;
			q.push(buil[i].f);
			ans++;
		}
	}
	cout <<ans;
	return 0;
}