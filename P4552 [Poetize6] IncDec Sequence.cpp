#include<bits/stdc++.h>
using namespace std;
#define int long long
int diff[100003];//�������
int n;
signed main(){
	cin >>n;
	int tmp,bef=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&tmp);
		diff[i]=tmp-bef;
		bef=tmp;
	}
//	cout <<"������������"<<endl;
//	for(int i=1;i<=n;i++){
//		printf("%d ",diff[i]);
//	}
//	cout <<endl;
	int operate=0;
	bool mark;
	for(int i=n;i>1;i--){
		if(diff[i]){
			bool stop=false;
			if(diff[i]>0){
				mark=true;
			}
			else{
				mark=false;
			}
			if(mark){
				for(int j=i-1;j>1;j--){
					if(-diff[j]>=diff[i]){
						operate+=diff[i];
						diff[j]+=diff[i];
						diff[i]=0;
						break;
					}
					else if(diff[j]<0){
						operate+=abs(diff[j]);
						diff[i]+=diff[j];
						diff[j]=0;
					}
				}
				if(diff[i]){//i֮ǰ���еĸ������޷��к����������Ҳ����˵������ֻʣ����һ��������
					stop=true;
					break;
				}
			}
			else{
				for(int j=i-1;j>1;j--){
					if(diff[j]>=-diff[i]){
						operate+=abs(diff[i]);
						diff[j]+=diff[i];
						diff[i]=0;
						break;
					}
					else if(diff[j]>0){
						operate+=diff[j];
						diff[i]+=diff[j];
						diff[j]=0;
					}
				}
				if(diff[i]){//i֮ǰ���е��������޷��к����������Ҳ����˵������ֻʣ����һ��������
					stop=true;
					break;
				}
			}
			if(stop){
				break;
			}
		}
	}
	//ͳ�Ʋ������ʣ�µ����ľ���ֵ֮��
	int sum=0;
	for(int i=2;i<=n;i++){
		sum+=abs(diff[i]);
	}
	cout <<operate+sum<<endl<<sum+1;
	return 0;
}