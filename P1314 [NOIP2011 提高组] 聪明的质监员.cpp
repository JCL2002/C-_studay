#include<bits/stdc++.h>
using namespace std;
struct mine{
	int w;
	int v;
}arr[200001]={{0,0}};
struct len{
	int l;
	int r;
}length[200001]={{0,0}};
int n,m;
long long s;
long long sum_w[200001];//wǰ׺��
long long sum_v[200001];//vǰ׺��
long long y(){//����sum�������y
	long long y=0;
	for(int i=1;i<=m;i++){
		y+=(sum_w[length[i].r]-sum_w[length[i].l-1])*(sum_v[length[i].r]-sum_v[length[i].l-1]);
	}
	return y;
}
void cal(int W){//����W����sum����
	for(int i=1;i<=n;i++){
		if(arr[i].w>=W){
			sum_w[i]=sum_w[i-1]+1;
			sum_v[i]=sum_v[i-1]+arr[i].v;
		}
		else{
			sum_w[i]=sum_w[i-1];
			sum_v[i]=sum_v[i-1];
		}
	}
}
int main(){
	cin >>n>>m>>s;
	int min=1,max=0;//���ַ�
	//����¼��
	for(int i=1;i<=n;i++){
		scanf("%d %d",&arr[i].w,&arr[i].v);
		if(arr[i].w>max){
			max=arr[i].w;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&length[i].l,&length[i].r);
	}
	long long Y=0;long long tmp;
	while(min<max){
		int mid=(min+max)/2;
		cal(mid);Y=y();
		if(Y>s){
			cal(mid+1);tmp=y();
			if(tmp>s){
				min=mid+1;
				continue;
			}
			else{
				if(abs(tmp-s)>abs(Y-s)){
					max=mid;
					break;
				}
				else{
					max=mid+1;
					break;
				}
			}
		}
		else{
			cal(mid-1);tmp=y();
			if(tmp>s){
				if(abs(tmp-s)>abs(Y-s)){
					max=mid;
					break;
				}
				else{
					max=mid-1;
					break;
				}
			}
			else{
				max=mid-1;
			}
		}
	}
	cal(max);
	cout <<abs(y()-s);
	//�����϶�������
	return 0;
}