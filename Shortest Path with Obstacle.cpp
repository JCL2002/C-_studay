 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
	 int t;cin >>t;
	 while(t--){
		 int ax,ay,bx,by,cx,cy;
		 cin >>ax>>ay>>bx>>by>>cx>>cy;
		 if(ax==bx&&bx==cx){//a,b,c在同一条直线上（水平）
			 if(cy>min(ay,by)&&cy<max(ay,by)){//夹在中间
				 cout <<abs(ay-by)+2<<endl;
				 continue;
			 }
			 else{
				 cout <<abs(ay-by)<<endl;
				 continue;
			 }
		 }
		 else if(ay==by&&by==cy){//a,b,c在同一条直线上（垂直）
			 if(cx>min(ax,bx)&&cx<max(ax,bx)){//夹在中间
				 cout <<abs(ax-bx)+2<<endl;
				 continue;
			 }
			 else{
				 cout <<abs(ax-bx)<<endl;
				 continue;
			 }
		 }
		 else{//不在一条线上
			 cout <<abs(ax-bx)+abs(ay-by)<<endl;
		 }
	 }
	 return 0;
}