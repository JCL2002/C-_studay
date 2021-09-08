#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int up[100005];
int down[100005];
int n;
int main(){
	while(cin >>arr[++n]);
	n--;
	//n为数字的个数
	int num_up=0;//最大上升子序列
	for(int i=1;i<=n;i++){
		if(arr[i]>up[num_up]){
			up[++num_up]=arr[i];
		}
		else{
			*lower_bound(up+1,up+1+num_up,arr[i])=arr[i];
		}
	}
	int num_down=0;
	for(int i=n;i>0;i--){
		if(arr[i]>=down[num_down]){
			down[++num_down]=arr[i];
		}
		else{
			*upper_bound(down+1,down+1+num_down,arr[i])=arr[i];
		}
	}
	cout <<num_down<<endl<<num_up;
	return 0;
}