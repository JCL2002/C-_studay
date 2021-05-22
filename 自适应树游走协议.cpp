#include<bits/stdc++.h>
using namespace std;
bool Request[4097]={false};
int times(int left,int right){
    int req=0;
    for(int i=left;i<=right;i++){
        if(Request[i])req++;
    }
    if(0==req||1==req) return 0;
    return 2+times(left,left+(right-left)/2)+times(left+(right-left)/2+1,right);
}
int main(){
    int n,k;cin >>n>>k;
    for(int i=1;i<=k;i++){//Êý¾ÝÂ¼Èë
        int p;
        cin >>p;
        Request[p]=true;
    }
    cout <<times(1,n)+1;
}