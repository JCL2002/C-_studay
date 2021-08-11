#include <bits/stdc++.h>
using namespace std;
char MAIN[550];
char MODE[1100];
bool flag;
int len_main, len_mode;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> MAIN >> MODE;
		len_main = strlen(MAIN);
		len_mode = strlen(MODE);
		for (int i = 0; i < len_main; i++) {
			flag = 0;
			if (MODE[0] == MAIN[i]) {
				if(len_mode==1)flag=true;//特判
				for (int j = 0; j < len_mode; j++) {//j代表右移步数
					int i_mode=0;
					int i_main=i;;
					//判断数组长度能不能满足移动
					if(i+j>=len_main) break;//无法满足右移步数，直接结束
					if(i+2*j<len_mode-1)continue;//无法满足左移步数，尝试增加右移步数
					//能够满足移动，判断移动是否能产生所需的字符串
//					i_mode++;
					bool asd=1;
					for(int ti=0;ti<j;ti++){//右移
						if(MAIN[++i_main]!=MODE[++i_mode])asd=0;
					}
//					cout <<"daozhele"<<endl;
					for(int ti=0;ti<len_mode-1-j;ti++){
						if(MAIN[--i_main]!=MODE[++i_mode])asd=0;
//						cout <<"main: "<<MAIN[i_main]<<" mode: "<<MODE[i_mode]<<endl;
					}
//					cout <<"到这了"<<endl;
					if(asd)
					flag = true;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}