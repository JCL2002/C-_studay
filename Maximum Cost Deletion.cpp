 #include<bits/stdc++.h>
 using namespace std;
 char str[120];
 int main(){
	int t;cin>>t;
	while(t--){
		int n,a,b;
		cin >>n>>a>>b;
		cin >>str;
		if(b>=0){//一个一段
			cout <<(a+b)*n<<endl;
		}
		else{//尽可能少地分段
			int i=1;int number=1;
			bool flag=str[0]-'0';
			while(str[i]!='\0'){
				if(str[i]-'0'!=flag){
					flag=str[i]-'0';
					number++;
				}
				i++;
			}
			cout <<a*n+((number/2)+1)*b<<endl;
		}
	} 
}