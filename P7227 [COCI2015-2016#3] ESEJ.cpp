#include<bits/stdc++.h>
using namespace std;
void pr(){
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
	printf("%c",97+rand()%26);
}
int  main(){
	srand(time(NULL));
	int a,b;
	cin >>a>>b;
	for(int i=0;i<(a+b)/2;i++){
		pr();
		printf(" ");
	}
	return 0;
}