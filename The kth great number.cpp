#include<iostream>
#include<queue>
using namespace std;
//int n,k;
//int sz;
//int tree[1000009];//Ð¡¸ùÊ÷
//char str[3];
//void swap(int& a,int& b){
//	int c=a;
//	a=b;
//	b=c;
//}
//void up(int i){
//	if(i/2&&tree[i]<tree[i/2]){
//		swap(tree[i],tree[i/2]);
//		up(i/2);
//	}
//}
//void down(int i){
//	if(2*i<=sz){
//		if(tree[2*i+1]<=sz){
//			int next;
//			if(tree[2*i]>tree[2*i+1]) next=2*i+1;
//			else next=2*i;
//			if(tree[i]>tree[next]){
//				swap(tree[i],tree[next]);
//				down(next);
//			}
//		}
//		else{
//			if(tree[i]>tree[2*i]){
//				swap(tree[i],tree[2*i]);
//				down(2*i);
//			}
//		}
//	}
//}
//int main(){
//	scanf("%d %d",&n,&k);
//	for(int i=1;i<=n;i++){
//		char o;int m;
//		cin >>o;
//		if(o=='I'){
//			if(i<=k){
//				scanf("%d",&m);
//				sz++;
//				tree[sz]=m;
//				up(sz);
//			}
//			else{
//				scanf("%d",&m);
//				if(m>tree[1]){
////					sz++;
////					tree[sz]=m;
////					up(sz);
////					swap(tree[1],tree[sz]);
////					sz--;
////					down(1);
//					tree[1]=m;
//					down(1);
//				}
//			}
//		}
//		else{
//			printf("%d\n",tree[1]);
//		}
//	}
//	return 0;
//}

int main(){
	int n,k;
	while(cin >>n>>k){
		priority_queue<int ,vector<int>,greater<int> >q;
	char cho;
	for(int i=1;i<=n;i++){
		cin >>cho;
		if(cho=='I'){
			int m;
			cin >>m;
			if(i<=k){
				q.push(m);
			}
			else{
				if(m>q.top()){
					q.pop();
					q.push(m);
				}
			}
		}
		else{
			cout <<q.top()<<endl;
		}
	}
}
	return 0;
}