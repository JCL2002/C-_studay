#include <bits/stdc++.h>
using namespace std;
char t[105];
char s[210];

int main()
{
	int n;
	cin >> n;
	while (n--) {
		cin >> t;
		bool z = 0, o = 0;
		for (int i = 0; i < (int)strlen(t); i++) {
			if (t[i] == '0')
				z = 1;
			else
				o = 1;
		}
		if (z && o) {
			int num = 0;
			s[num++] = t[0];
			for (int i = 1; i < (int) strlen(t); i++) {
				if(t[i]==t[i-1]){
					if(t[i]=='0'){
						s[num++]='1';
						s[num++]=t[i];
					}
					else{
						s[num++]='0';
						s[num++]=t[i];
					}
				}
				else{
					s[num++]=t[i];
				}
			}
			s[num]='\0';
			cout <<s<<endl;
		} else if (z) {
			for (int i = 0; i < (int) strlen(t); i++) {
				cout << 0;
			}
			cout << endl;
		} else if (o) {
			for (int i = 0; i < (int) strlen(t); i++) {
				cout << 1;
			}
			cout << endl;
		}

	}
	return 0;
}