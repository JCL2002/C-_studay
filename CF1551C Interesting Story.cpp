#include<bits/stdc++.h>
using namespace std;
struct word{
	int num[6];
};
word arr[200005];
string s;
int c;
bool cmp(word a,word b){
	return 2*a.num[c]-a.num[0]>2*b.num[c]-b.num[0];
}
int main(){
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>s;
			arr[i].num[0]=s.length();
			for(int j=1;j<6;j++)arr[i].num[j]=0;//初始化
			for(int j=0;j<arr[i].num[0];j++){
				arr[i].num[(int)s[j]-'a'+1]++;
			}
		}
		int num=0;
		for(c=1;c<6;c++){
			long long sum=0;//字母数量总和
			long long target=0;//目标字母总和
			int j=0;
			sort(arr+1,arr+1+n,cmp);
			for(;j<n&&(sum+arr[j+1].num[0])<(2*(target+arr[j+1].num[c]));j++){
				sum+=arr[j+1].num[0];
				target+=arr[j+1].num[c];
			}
			num=max(num,j);
		}
		cout <<num<<endl;
	}
	return 0;
}