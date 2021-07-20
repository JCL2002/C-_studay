#include<bits/stdc++.h>
using namespace std;
int t,h,w;
int main(){
	cin >>t;
	while(t--){
		cin >>h>>w;
		for(int i=0;i<h;i++){
			if(i==0){
				for(int j=0;j<w;j++){
					if(j%2==0) {
						cout <<1;
					}
					else{
						cout <<0;
					}
				}
			}
			else if(i%2==0&&i!=h-1){
				cout <<1;for(int j=1;j<w-1;j++){
					cout <<0;
				}
				cout <<1;
			}
			else if(i%2&&i!=h-1){
				for(int j=0;j<w;j++){
					cout <<0;
				}
			}
			else{
				if(i%2==0){
					for(int j=0;j<w;j++){
						if(j%2==0) {
							cout <<1;
						}
						else{
							cout <<0;
						}
					}
				}
				else{
					cout <<0<<0;
					for(int j=3;j<=w-2;j++){
						if(j%2) cout <<1;
						else cout <<0;
					}
					if(w>3) cout <<0 <<0;
					else cout <<0;
				}
			}
			cout <<endl;
		}
		cout <<endl;
	}
	return 0;
}