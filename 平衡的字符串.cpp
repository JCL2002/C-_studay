#include<bits/stdc++.h>
using namespace std;
char inp[1000001];
int main(){
	int n,k;
	cin >>n>>k;
	cin >>inp;
	if(k&1){//��������
		cout <<"No";
		return 0;
	}
	bool ok;
	//��ʼ�ж�
	int o=0,z=0;
	for(int i=0;i<k;i++){
		if(inp[i]=='0')z++;
		if(inp[i]=='1')o++;
	}
//	cout <<o<<'\t'<<z<<endl;
	if(z<=k/2&&o<=k/2){
		ok=true;
	}
	else{
		ok=false;
	}
	//inp[x]=inp[x+k]
	for(int i=0;i<n-k;i++){
		if(inp[i]=='?'){//����
			inp[i]=inp[i+k];
			continue;
		}
		if(inp[i]=='0'){
			if(inp[i+k]=='0'){
				continue;
			}
			else if(inp[i+k]=='?'){
				inp[i+k]='0';
				continue;
			}
			else{
				ok=false;
				break;
			}
		}
		if(inp[i]=='1'){
			if(inp[i+k]=='1'){
				continue;
			}
			else if(inp[i+k]=='?'){
				inp[i+k]='1';
				continue;
			}
			else{
				ok=false;
				break;
			}
		}
	}
	//��β�ж�
	if(ok){//����
		o=0;z=0;
		for(int i=0;i<k;i++){
			if(inp[i]=='0')z++;
			if(inp[i]=='1')o++;
		}
		if(z<=k/2&&o<=k/2){
			ok=true;
		}
		else{
			ok=false;
		}
	}
	if(ok){//β��
		o=0;z=0;
		for(int i=n-k;i<n;i++){
			if(inp[i]=='0')z++;
			if(inp[i]=='1')o++;
		}
		if(z<=k/2&&o<=k/2){
			ok=true;
		}
		else{
			ok=false;
		}
	}
	if(ok){
		cout <<"Yes";
	}
	else{
		cout <<"No";
	}
	return 0;
}