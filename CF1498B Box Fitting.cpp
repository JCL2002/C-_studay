#include<bits/stdc++.h>
using namespace std;
int power(int x){
    int base=2;
    int res=1;
    while(x){
        if(x&1) res*=base;
        base*=base;
        x>>=1;
    }
    return res;
}
int arr[25];
int main(){
    int t;
    cin >>t;
    while(t--){
        int n,w;
        for(int i=0;i<25;i++) arr[i]=0;
        cin >>n>>w;
        for(int i=0;i<n;i++){
            int tmp;
            cin >>tmp;
            int j=-1;
            while(tmp){
                j++;
                tmp>>=1;
            }
            arr[j]++;
        }
//        for(int i=0;i<24;i++) cout <<arr[i]<<" ";
//        cout <<endl;
        int num=0;
        while(n>0){
            num++;
            int W=w;
            for(int i=24;i>=0;i--){
                if(arr[i]&&W>=power(i)){
                    arr[i]--;
                    n--;
                    W-=power(i);
                    i++;
                }
            }
        }
        cout <<num<<endl;
    }
    return 0;
}
