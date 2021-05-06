#include <bits/stdc++.h>
using namespace std;

void cal(int &x, int &y, int &sum) {
	if (sum == 2) { //特殊情况
		x = 1;
		y = 1;
		}
	if (!sum && x && y) {
		sum = x + y;
		return ;
		}
	if (!x && sum && y) {
		x = sum - y;
		return ;
		}
	if (!y && sum && x) {
		y = sum - x;
		return ;
		}
	}

int main() {
	int M[3][3];
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M[0][0], &M[0][1], &M[0][2]);
		scanf("%d %d %d", &M[1][0], &M[1][1], &M[1][2]);
		scanf("%d %d %d", &M[2][0], &M[2][1], &M[2][2]);
		int abcd=0;//abcd的个数
		int abcd_x[4],abcd_y[4];//为零的abcd的坐标
		int x=0;
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(M[j][k]==0){
					abcd++;
					abcd_x[x]=j;abcd_y[x]=k;
					x++;
				}
			}
		}
		if((M[2][2]-M[0][0]-M[0][1]-M[1][0]-M[1][1])==abcd){
			for(int j=0;j<abcd;j++){
				M[abcd_x[j]][abcd_y[j]]=1;
			}
		}
		for (int h = 0; h < 2; h++) {
			for (int j = 0; j < 3; j++) {
				cal(M[j][0], M[j][1], M[j][2]);
				}
			for (int j = 0; j < 3; j++) {
				cal(M[0][j], M[1][j], M[2][j]);
				}
			}
		bool zero = false; //检查矩阵里面是否还有0
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (M[j][k] == 0) {
					zero = true;
					break;
					}
				}
			if (zero) {
				break;
				}
			}
		if (zero)
			printf("NO\n");
		else {
			printf("YES\n");
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					printf("%d", M[j][k]);
					if (k < 2) {
						printf(" ");
						}
					}
				printf("\n");
				}
			}
		}
	return 0;
	}