#include<bits/stdc++.h>
using namespace std;
char vig(char c,int n){
	n%=26;//���������û��
	if(c>='A'&&c<='Z'){//��д
		if(c-(char)n>='A'){
			return c-(char)n;
		}
		else{
			return c-(char)n+26;
		}
	}
	else{
		if(c-(char)n>='a'){
			return c-(char)n;
		}
		else{
			return c-(char)n+26;
		}
	}
}
int main(){
	char M[1001],k[101];
	cin >> k >>M;
	for(int i=0,j=0;i<strlen(M);i++,j++){
		if(k[j]-'a'>=0){//Сд���
			cout << vig(M[i],k[j]-'a');
		}
		else{
			cout << vig(M[i],k[j]-'A');
		}
		if(j==strlen(k)-1){
			j=-1;
		}
	}
	return 0;
}