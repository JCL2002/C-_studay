 #include<bits/stdc++.h>
 using namespace std;
 char str[27];
 
 int main(){
	 int t;cin >>t;
	 while(t--){
		 cin >>str;
		 int len=(int)strlen(str);
		 int l=0,r=len-1;
		 bool flag=true;
		 while(len--){
			 if('a'+len==str[l]){
				 l++;
				 continue;
			 }
			 else if('a'+len==str[r]){
				 r--;
				 continue;
			 }
			 else{
				 flag=false;
				 break;
			 }
		 }
		 if(flag) cout <<"YES"<<endl;
		 else cout <<"NO"<<endl;
	 }
	return 0; 
}