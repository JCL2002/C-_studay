#include<bits/stdc++.h>
using namespace std;
int arr[502][502];
int p[502];
int main(){
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		arr[i][0]=-1;
		arr[n+1][i]=-1;
	}
	for(int i=1;i<=n;i++) cin >>p[i];
	bool flag=1;
	for(int i=1;i<=n;i++){
		int x=i,y=i+1;
		int j=p[i];
		while(j--){
//			cout <<x<<" "<<y<<endl;;
			if(arr[x][y-1]){
				if(arr[x+1][y]){
					flag=0;
					
					break;
				}
				x++;
			}
			else y--;
			arr[x][y]=p[i];
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cout <<arr[i][j]<<" ";
			}
			cout <<endl;
		}
	}
	else cout <<-1;
	return 0;
}