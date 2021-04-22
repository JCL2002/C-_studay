#include<bits/stdc++.h>
using namespace std;
struct stu{
	char name[64];
	int score;
};
int main(){
	int i,n;
	bool d;
	cin >>n;
	cin >>d;
	stu L[5000],cache;
	for(i=0;i<n;i++){
		cin >> L[i].name >> L[i].score;
	}
	int j;
	if(!d){
		for(i=1;i<n;i++){
			for(j=0;j<n-i;j++){
				if(L[j].score<L[j+1].score){
					cache=L[j];
					L[j]=L[j+1];
					L[j+1]=cache;
				}
			}
		}
	}
	else{
		for(i=1;i<n;i++){
			for(j=0;j<n-i;j++){
				if(L[j].score>L[j+1].score){
					cache=L[j];
					L[j]=L[j+1];
					L[j+1]=cache;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		cout << L[i].name << ' '<< L[i].score<<endl;
	}
	return 0;
}