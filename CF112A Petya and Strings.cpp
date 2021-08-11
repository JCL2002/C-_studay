#include <bits/stdc++.h>
using namespace std;
char a[200];
char b[200];

int main()
{
	cin >> a;
	cin >> b;
	for(int i=0;i<(int)strlen(a);i++){//同一转换成大写
		if(a[i]>='a'&&a[i]<='z')a[i]-=32;
		if(b[i]>='a'&&a[i]<='z') b[i]-=32;
	}
	cout <<strcmp(a,b);
	return 0;
}