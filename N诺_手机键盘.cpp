#include<bits/stdc++.h>
using namespace std;
int v[26]={0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7};
int main(){
	char Input[101],cache[101];
	while(true){
		int time=0;
		int i;
		cin >> cache;
		if(!strcmp(Input,cache)){
			break;
		}
		strcpy(Input,cache);
		for(i=0;i<strlen(Input);i++){
			if(i){//不是第一个字母
				if(v[Input[i]-'a']==v[Input[i-1]-'a']){//同一按键
					time+=2;
				}
			}
			//判断按键时间
			if(v[Input[i]-'a']==0){
				time+=(Input[i]-'a');
			}
			else if(v[Input[i]-'a']==1){
				time+=(Input[i]-'d');
			}
			else if(v[Input[i]-'a']==2){
				time+=(Input[i]-'g');
			}
			else if(v[Input[i]-'a']==3){
				time+=(Input[i]-'j');
			}
			else if(v[Input[i]-'a']==4){
				time+=(Input[i]-'m');
			}
			else if(v[Input[i]-'a']==5){
				time+=(Input[i]-'p');
			}
			else if(v[Input[i]-'a']==6){
				time+=(Input[i]-'t');
			}
			else{
				time+=(Input[i]-'w');
			}
			time++;
		}
		cout << time<<endl;
	}
	return 0;
}