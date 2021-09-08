#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>school[200005];
struct oier{
	int belong;//归属学校
	long long level;//水平
};
oier arr[200005];
long long ans[200005];
int n;
bool cmp(oier a,oier b){
	return a.level>b.level;
}
void init(){
	for(int i=0;i<=n;i++){
		school[i].clear();
		ans[i]=0;
	}
}
int main(){
	int t;cin >>t;
	while(t--){
		cin >>n;
		for(int i=1;i<=n;i++) cin >> arr[i].belong;
		for(int i=1;i<=n;i++) cin >> arr[i].level;
		sort(arr+1,arr+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(school[arr[i].belong].size()) school[arr[i].belong].push_back((school[arr[i].belong][school[arr[i].belong].size()-1]+arr[i].level));
			else school[arr[i].belong].push_back(arr[i].level);
		}
		for(int i=1;i<=n;i++){
			if(school[i].size()){
				for(int j=1;j<(int)school[i].size();j++){
					ans[j]+=school[i][(school[i].size()-1)-(school[i].size()%j)];
				}
				ans[school[i].size()]+=school[i][school[i].size()-1];
			}
		}
		for(int i=1;i<=n;i++) cout <<ans[i]<<" ";
		cout <<endl;
//		cout <<school[1][0]<<" "<<school[1][1]<<endl;
//		cout <<school[2][0]<<" "<<school[2][1]<<endl;
		init();
	}
	return 0;
}