#include<bits/stdc++.h>
using namespace std;
int arr[2001];
int ji[2001];
int ou[2001];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int t,n;
	cin >>t;
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		//Çø·ÖÆæÅ¼
		int nj=1,no=1;
		for(int j=1;j<=n;j++){
			int tmp;
			scanf("%d",&tmp);
			if(tmp&1){
				ji[nj++]=tmp;
			}
			else{
				ou[no++]=tmp;
			}
			}
			sort(ou+1,ou+no,cmp);sort(ji+1,ji+nj,cmp);
			int j=1;
			for(int k=1;k<no;k++){
				arr[j]=ou[k];
				j++;
			}
			for(int k=1;k<nj;k++){
				arr[j]=ji[k];
				j++;
			}
			int num=0;
			for(int j=1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(gcd(arr[j],2*arr[k])>1){
						num++;
					}
				}
			}
			cout <<num<<endl;
	}
	return 0;
}