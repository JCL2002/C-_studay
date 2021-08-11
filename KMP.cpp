#include <bits/stdc++.h>
using namespace std;
const int N = 100002;

int NEXT[N];//next���飬�洢���� 
char MAIN[N];//����
char MODE[N];//ģʽ��
void cal_next() //����next����
{
	int n = strlen(MODE);
	NEXT[0] = -1;
	for (int i = 1; i < n; i++) {
		int j = NEXT[i - 1];
		while (j > -1 && MODE[i] != MODE[j + 1])
			j = NEXT[j];
		if (MODE[i] == MODE[j + 1])
			NEXT[i] = j + 1;
		else
			NEXT[i] = -1;
	}
}

int kmp()
{
	int len_MODE=strlen(MODE);
	for (int i = 0,j=0; i <= (int)strlen(MAIN);) {
		if(MAIN[i]!=MODE[j]){
			if(j==0){
				i++;
			}
			else{
				j=NEXT[j-1]+1;
			}
		}
		else{
			i++;j++;
			if(j==len_MODE) return i-j;
		}
	}
	return -1;
}

int main()
{
	cin >> MAIN;
	cin >> MODE;
	cal_next();
	cout <<kmp();
	return 0;
}