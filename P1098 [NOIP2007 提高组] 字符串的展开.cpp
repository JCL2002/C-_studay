#include<bits/stdc++.h>
using namespace std;
int p[4];
char in[202];
char out[35007];
int main(){
	cin >>p[1]>>p[2]>>p[3];
	cin >>in;
	int k=0;
	for(int i=0;i<(int)strlen(in);i++){
		if(in[i]=='-'&&in[i-1]<in[i+1]&&abs((int)in[i-1]-in[i+1])<27&&i!=0&&i!=(int)strlen(in)-1&&((in[i-1]>='0'&&in[i-1]<='9')||(in[i-1]>='A'&&in[i-1]<='Z')||(in[i-1]>='a'&&in[i-1]<='z'))&&((in[i+1]>='0'&&in[i+1]<='9')||(in[i+1]>='A'&&in[i+1]<='Z')||(in[i+1]>='a'&&in[i+1]<='z'))){
			char left,right;left=in[i-1];right=in[i+1];
			char left_a,left_A;
			if(left>='a'&&right>='a'){
				left_a=left;
				left_A=left-32;
			}
			else if(left<'A'&&right<'A'){//Êı×Ö
				left_a=left;
				left_A=left;
			}
			else{
				left_a=left+32;
				left_A=left;
			}
			if(p[3]==1){
				for(int i=1;i<(int)right-left;i++){
					if(p[1]==1){//ÌîĞ´Ğ¡Ğ´×ÖÄ¸
						for(int j=0;j<p[2];j++){
							out[k++]=left_a+i;
						}
					}
					if(p[1]==2){//ÌîĞ´´óĞ´×ÖÄ¸
						for(int j=0;j<p[2];j++){
							out[k++]=left_A+i;
						}
					}
					if(p[1]==3){//ÌîĞ´*
						for(int j=0;j<p[2];j++){
							out[k++]='*';
						}
					}
				}
			}
			else{//ÄæĞòÊä³ö
				for(int i=(int)right-left-1;i>0;i--){
					if(p[1]==1){//ÌîĞ´Ğ¡Ğ´×ÖÄ¸
						for(int j=0;j<p[2];j++){
							out[k++]=left_a+i;
						}
					}
					if(p[1]==2){//ÌîĞ´´óĞ´×ÖÄ¸
						for(int j=0;j<p[2];j++){
							out[k++]=left_A+i;
						}
					}
					if(p[1]==3){//ÌîĞ´*
						for(int j=0;j<p[2];j++){
							out[k++]='*';
						}
					}
				}
			}
		}
		else{
			out[k++]=in[i];
		}
	}
	cout <<out;
	return 0;
}