#include<bits/stdc++.h>
using namespace std;
int sum[5002][5002];
int main(){
	int n,m;
	cin >> n >> m;
	int max_x=0,max_y=0;
	for(int i=0;i<n;i++){
		int x,y;int v;
		scanf("%d %d %d",&x,&y,&v);
		sum[x+1][y+1]=v;
		//�ҳ��߽�,�������������
		if(x+1>max_x) max_x=x+1;
		if(y+1>max_y) max_y=y+1;
	}
	//����ǰ׺������
	for(int x=1;x<=max_x;x++){
		for(int y=1;y<=max_y;y++){
			sum[x][y]+=sum[x-1][y]+sum[x][y-1]-sum[x-1][y-1];
		}
	}
	int MAX=0;
	//ȷ������߽�
	/*
	1:��m<=max_x&&m<=max_yʱ����(m,m)��(max_x,max_y);
	2:��m<=max_x&&m>max_yʱ����(m,max_y)��(max_x,max_y);
	3:��m>max_x&&m<=max_yʱ����(max_x,m)��(max_x,max_y);
	4:��m>max_x&&m>max_yʱ����(max_x,max_y)��(max_x,max_y);
	�ܽ���ɣ���(min(m,max_x),min(m,max_y))��(max_x,max_y);
	�Ӷ���֤���������ȫ������ǰ׺�͵ļ��㣬���Ҽ�������С
	*/
	for(int x=min(m,max_x);x<=max_x;x++){
		for(int y=min(m,max_y);y<=max_y;y++){
			//�����ǵ�������(m,m)ʱ��ֹ�±�Խ��
			int a,b;
			a=x-m;b=y-m;
			if(a<0) a=0;
			if(b<0) b=0;
			int tmp=sum[x][y]-sum[a][y]-sum[x][b]+sum[a][b];
			if(tmp>MAX) MAX=tmp;
		}
	}
	cout <<MAX;
	return 0;
}