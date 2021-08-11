#include<bits/stdc++.h>
using namespace std;
char a[120];
char b[120];
char c[120];
char d[120];
int num[256];
int main(){
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	for(int i=0;i<(int)strlen(a);i++){
		num[(int)a[i]]++;
	}
	for(int i=0;i<(int)strlen(b);i++){
		num[(int)b[i]]++;
	}
	for(int i=0;i<(int)strlen(c);i++){
		num[(int)c[i]]++;
	}
	for(int i=0;i<(int)strlen(d);i++){
		num[(int)d[i]]++;
	}
	int MAX=0;
	for(int i=(int)'A';i<=(int)'Z';i++){
		MAX=max(MAX,num[i]);
	}
	for(int i=MAX;i>0;i--){
		for(int j=(int)'A';j<=(int)'Z';j++){
			if(num[j]>=i){
				cout <<'*';
			}
			else{
				cout <<' ';
			}
			if(j!=(int)'Z') cout <<' ';
		}
		cout <<endl;
	}
	cout <<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
	return 0;
}