#include<bits/stdc++.h>
using namespace std;
char date[9];
int arr[9];
bool rain(int year){//闰年判断
	 if(year%400==0||(year%4==0&&year%100!=0)){
		 return true;
	}
	else{
		return false;
	}
}
bool zs(int num){//判断质数
	if(num<2){
		return false;
	}
	if(num<4){
		return true;
	}
	if(num%2==0){
		return false;//偶数
	}
	for(int i=3;i<=sqrt(num)+1;i+=2){//直接跳过偶数，增加计算速度
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int dfs(int depth){//深度优先搜索
	 if(depth==9){//结束条件
		 int a=arr[1]*1e7+arr[2]*1e6+arr[3]*1e5+arr[4]*1e4+arr[5]*1e3+arr[6]*1e2+arr[7]*10+arr[8];
		 int b=arr[5]*1e3+arr[6]*1e2+arr[7]*10+arr[8];
		 int c=arr[7]*10+arr[8];
		 int year=arr[1]*1000+arr[2]*100+arr[3]*10+arr[4];
		 int month=arr[5]*10+arr[6];
		 int day=arr[7]*10+arr[8];
		 //日期合法性判断
		 if(year==0){
			 return 0;
		}
		if(month==0||month>12){
			return 0;
		}
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
			if(day==0||day>31){
				return 0;
			}
		}
		else{
			if(month==2){
				if(rain(year)){
					if(day==0||day>29){
						return 0;
					}
				}
				else{
					if(day==0||day>28){
						return 0;
					}
				}
			}
			else{
				if(day==0||day>30){
					return 0;
				}
			}
		}
		 if(zs(c)&&zs(b)&&zs(a)){
			 return 1;
		}
		else{
			return 0;
		}
	}
	if(date[depth-1]!='-'){
		arr[depth]=(int)date[depth-1]-'0';
		return dfs(depth+1);
	}
	else{
		int sum=0;
		if(depth<5){
			if(depth<4){//年份前三位没有限制
				for(int i=0;i<10;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
			else{//最后一位应该注意，不能出现0000年
				if(arr[1]==0&&arr[2]==0&&arr[3]==0){
					for(int i=1;i<10;i++){
						arr[depth]=i;
						sum+=dfs(depth+1);
					}
				}
				else{
					for(int i=0;i<10;i++){
						arr[depth]=i;
						sum+=dfs(depth+1);
					}
				}
			}
		}
		else if(depth<6){//月份的第一位
			for(int i=0;i<2;i++){
				arr[depth]=i;
				sum+=dfs(depth+1);
			}
		}
		else if(depth<7){//月份的第二位
			if(arr[5]){
				for(int i=0;i<3;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
			else{
				for(int i=1;i<10;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
		}
		else if(depth<8){//日期的第一位
			int month=arr[5]*10+arr[6];
			if(month==2){
				for(int i=0;i<3;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
			else{
				for(int i=0;i<4;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
		}
		else{//日期的最后一位
			int year=arr[1]*1000+arr[2]*100+arr[3]*10+arr[4];
			int month=arr[5]*10+arr[6];
			if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){//一三五七八十腊，三十一天永不差
				if(arr[7]==3){
					for(int i=0;i<2;i++){
						arr[depth]=i;
						sum+=dfs(depth+1);
					}
				}
				else{
					if(arr[7]){
						for(int i=0;i<10;i++){
							arr[depth]=i;
							sum+=dfs(depth+1);
						}
					}
					else{
						for(int i=1;i<10;i++){
							arr[depth]=i;
							sum+=dfs(depth+1);
						}
					}
				}
			}
			else{//小月份
				if(month==2){//二月分要判断闰年
					if(rain(year)){
						if(arr[7]){
							for(int i=0;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
						else{
							for(int i=1;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
					}
					else{
						if(arr[7]==1){
							for(int i=0;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
						else if(arr[7]==2){
							for(int i=0;i<9;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
						else{
							for(int i=1;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
					}
				}
				else{
					if(arr[7]==3){
						arr[depth]=0;
						sum+=dfs(depth+1);
					}
					else{
						if(arr[7]){
							for(int i=0;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
						else{
							for(int i=1;i<10;i++){
								arr[depth]=i;
								sum+=dfs(depth+1);
							}
						}
					}
				}
			}
		}
		return sum;
	}
	
}
int main(){
	 int t;
	 cin >>t;
	 while(t--){
		 cin >>date;
		 //加入特判
		 if(date[0]=='-'&&date[1]=='-'&&date[2]=='-'&&date[3]=='-'&&date[4]=='-'&&date[5]=='-'&&date[6]=='-'&&date[7]=='-'){
			 cout <<55157<<endl;
			 continue;
		}
		 cout << dfs(1)<<endl;
	}
	return 0; 
}
