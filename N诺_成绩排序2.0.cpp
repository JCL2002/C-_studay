#include<bits/stdc++.h>
using namespace std;
struct stu{
	int id;
	int score;
};
int main(){
	stu List[1000],cache;
	int i,j,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >>List[i].id >>List[i].score;
	}
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(List[j].score>List[j+1].score){
				cache=List[j];
				List[j]=List[j+1];
				List[j+1]=cache;
			}
		}
	}
	for(i=0;i<n;i++){
		cout <<List[i].id <<' '<<List[i].score <<endl;
	}
	return 0;
}