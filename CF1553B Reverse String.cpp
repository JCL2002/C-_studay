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
				if(len_mode==1)flag=true;//����
				for (int j = 0; j < len_mode; j++) {//j�������Ʋ���
					int i_mode=0;
					int i_main=i;;
					//�ж����鳤���ܲ��������ƶ�
					if(i+j>=len_main) break;//�޷��������Ʋ�����ֱ�ӽ���
					if(i+2*j<len_mode-1)continue;//�޷��������Ʋ����������������Ʋ���
					//�ܹ������ƶ����ж��ƶ��Ƿ��ܲ���������ַ���
//					i_mode++;
					bool asd=1;
					for(int ti=0;ti<j;ti++){//����
						if(MAIN[++i_main]!=MODE[++i_mode])asd=0;
					}
//					cout <<"daozhele"<<endl;
					for(int ti=0;ti<len_mode-1-j;ti++){
						if(MAIN[--i_main]!=MODE[++i_mode])asd=0;
//						cout <<"main: "<<MAIN[i_main]<<" mode: "<<MODE[i_mode]<<endl;
					}
//					cout <<"������"<<endl;
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