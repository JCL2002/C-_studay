#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
	int n;cin >>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int number=0;int max_of_swap=0;
	for(int i=0;i<n;i++){
		if(i==arr[i]){
			number++;
		}
		else if(max_of_swap!=2){
			if(arr[arr[i]]!=arr[i]){//Ϊ�ɽ���Ԫ��
				if(arr[arr[i]]==i){
					max_of_swap=2;
				}
				else{
					max_of_swap=1;
				}
			}
		}
	}
	//�����жϽ������ܵ���������fix������
	cout<<number+max_of_swap;
	return 0;
}