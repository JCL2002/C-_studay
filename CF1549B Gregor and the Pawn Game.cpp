#include<bits/stdc++.h>
using namespace std;
char enemy[200005];
char pawn[200005];
int main(){
	int t;
	cin >>t;
	while(t--){
		int len;
		cin >>len;
		cin >>enemy+1;
		cin >>pawn+1;
		int sum=0;
		enemy[0]='-';//-表示自己人
		enemy[len+1]='-';
		for(int i=1;i<=len;i++){
			if(pawn[i]=='1'){
				if(enemy[i]=='0'){
					sum++;
					enemy[i]='-';
				}
				else{
					if(enemy[i-1]=='1'){
						sum++;
						enemy[i-1]='-';//有没有都行
					}
					else if(enemy[i+1]=='1'){
						sum++;
						enemy[i+1]='-';//必须有
					}
				}
			}
		}
//		cout <<enemy<<endl;
		cout <<sum<<endl;
	}
	return 0;
}