#include<bits/stdc++.h>
using namespace std;
char date[9];
int arr[9];
bool rain(int year){//�����ж�
	 if(year%400==0||(year%4==0&&year%100!=0)){
		 return true;
	}
	else{
		return false;
	}
}
bool zs(int num){//�ж�����
	if(num<2){
		return false;
	}
	if(num<4){
		return true;
	}
	if(num%2==0){
		return false;//ż��
	}
	for(int i=3;i<=sqrt(num)+1;i+=2){//ֱ������ż�������Ӽ����ٶ�
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int dfs(int depth){//�����������
	 if(depth==9){//��������
		 int a=arr[1]*1e7+arr[2]*1e6+arr[3]*1e5+arr[4]*1e4+arr[5]*1e3+arr[6]*1e2+arr[7]*10+arr[8];
		 int b=arr[5]*1e3+arr[6]*1e2+arr[7]*10+arr[8];
		 int c=arr[7]*10+arr[8];
		 int year=arr[1]*1000+arr[2]*100+arr[3]*10+arr[4];
		 int month=arr[5]*10+arr[6];
		 int day=arr[7]*10+arr[8];
		 //���ںϷ����ж�
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
			if(depth<4){//���ǰ��λû������
				for(int i=0;i<10;i++){
					arr[depth]=i;
					sum+=dfs(depth+1);
				}
			}
			else{//���һλӦ��ע�⣬���ܳ���0000��
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
		else if(depth<6){//�·ݵĵ�һλ
			for(int i=0;i<2;i++){
				arr[depth]=i;
				sum+=dfs(depth+1);
			}
		}
		else if(depth<7){//�·ݵĵڶ�λ
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
		else if(depth<8){//���ڵĵ�һλ
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
		else{//���ڵ����һλ
			int year=arr[1]*1000+arr[2]*100+arr[3]*10+arr[4];
			int month=arr[5]*10+arr[6];
			if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){//һ�����߰�ʮ������ʮһ��������
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
			else{//С�·�
				if(month==2){//���·�Ҫ�ж�����
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
		 //��������
		 if(date[0]=='-'&&date[1]=='-'&&date[2]=='-'&&date[3]=='-'&&date[4]=='-'&&date[5]=='-'&&date[6]=='-'&&date[7]=='-'){
			 cout <<55157<<endl;
			 continue;
		}
		 cout << dfs(1)<<endl;
	}
	return 0; 
}
