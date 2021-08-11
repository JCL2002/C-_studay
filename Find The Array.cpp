 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	 int t;cin>>t;
	 while(t--){
		 int s;
		 cin >>s;
		 int res=sqrt(s);
		 if(res*res==s){
			 cout <<res<<endl;
			 continue;
		 }
		 cout <<res+1<<endl;
	 }
	return 0; 
}