#include<bits/stdc++.h>
using namespace std;
int arr[30003];
int HASH[202];//��ϣ����
int main(){
	int w,n;
	cin >>w>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		HASH[tmp]++;
	}
	for(int i=5,j=1;i<=200;i++){
		for(int k=1;k<=HASH[i];k++,j++){
			arr[j]=i;//����HASH���黹ԭ����õ�arr����
		}
	}
	int min=1,max=n;
	int num=0;
	while(min<=max){
		if(arr[max]+arr[min]>w){
			num++;
			max--;
		}
		else{
			num++;max--;min++;
		}
	}
	cout <<num;
	return 0;
}