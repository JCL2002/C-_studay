#include<bits/stdc++.h>
using namespace std;
char str[12];


int main(){
	int t;cin >>t;
	for(int i=1;i<=t;i++){
		cin >>str;
		int sa=0,sb=0;int min_a=10;int min_b=10;
		//假设a队的？全部进球
		for(int i=0;i<10;i++){
			if(i%2==0){//a踢球
				if(str[i]!='0') sa++;
				if((sa-sb)>(9-i)/2+1||(sb-sa)>(9-i)/2){
					min_a=i+1;
					break;
				}
			}
			else{//b踢球
				if(str[i]=='1') sb++;
				if(sb-sa>(9-i)/2||(sa-sb)>(9-i)/2){
					min_a=i+1;
					break;
				}
			}
		}
//		cout <<"sa:"<<sa<<endl<<"sb:"<<sb<<endl;
//		cout <<min_a<<endl;
		//假设b队的球全进
		sa=0;sb=0;
		for(int i=0;i<10;i++){
			if(i%2==0){
				if(str[i]=='1')sa++;
				if(sa-sb>(9-i)/2+1||(sb-sa)>(9-i)/2){
					min_b=i+1;
					break;
				}
			}
			else{
				if(str[i]!='0')sb++;
				if(sb-sa>(9-i)/2||(sa-sb)>(9-i)/2){
					min_b=i+1;
					break;
				}
			}
		}
		cout <<min(min_a,min_b)<<endl;
	}
	return 0;
}