#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//小根堆求最大，大根堆求最小
int main(){
	int t;cin >>t;
	while(t--){
		priority_queue<int,vector<int>> L;
		int n;cin >>n;
		for(int i=1;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(i<3){
				L.push(tmp);
			}
			else{
				if(tmp<L.top()){
					L.pop();
					L.push(tmp);
				}
			}
		}
		cout <<L.top()<<endl;
	}
	
	return 0;
}