#include<bits/stdc++.h>
using namespace std;
char a[50];
char b[50];
bool cmp(char* main,char* mode,int len){
	int len_main=strlen(main);
	for(int i=0;i<=len_main-len;i++){
		if(main[i]==mode[0]){
			for(int j=0;j<len;j++){
				if(main[i+j]!=mode[j]){
					break;
				}
				if(j==len-1)return 1;
			}
			
		}
	}
	return 0;
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>a;
		cin >>b;
		int len_a=strlen(a),len_b=strlen(b);
		int max=0;
		if(len_a>=len_b){
			//��b�н�ȡ�ֶΣ���aƥ��
			for(int i=len_b;i>0;i--){//���ȿ���
				for(int j=0;j<=len_b-i;j++){
					if(cmp(a,b+j,i)){
						max=i;
						break;
					}
				}
				if(max)break;
			}
		}
		else{
			//��a�н�ȡ�ֶΣ���b��ƥ��
			for(int i=len_a;i>0;i--){
				for(int j=0;j<=len_a-i;j++){
					if(cmp(b,a+j,i)){
						max=i;
						break;
					}
				}
				if(max) break;
			}
		}
		cout <<len_a+len_b-2*max<<endl;
	}
	return 0;
}