#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int n;
int main(){
    int t;
    cin >>t;
    while(t--){
        cin >>n;
        for(int i=1;i<=n;i++) cin >>arr[i];
        int num=0;
        bool flag;
        while(true){
            flag=0;
            for(int i=1;i<=n;i++) if(arr[i]<arr[i-1]){flag=1; break;}
            if(!flag)break;
            for(int i=1;i<n;i+=2){
                if(arr[i]>arr[i+1]){
                    arr[i]^=arr[i+1];
                    arr[i+1]^=arr[i];
                    arr[i]^=arr[i+1];
                }
            }
            num++;
            flag=0;
            for(int i=1;i<=n;i++) if(arr[i]<arr[i-1]){flag=1; break;}
            if(!flag)break;
            for(int i=2;i<n;i+=2){
                if(arr[i]>arr[i+1]){
                    arr[i]^=arr[i+1];
                    arr[i+1]^=arr[i];
                    arr[i]^=arr[i+1];
                }
            }
            num++;
        }
        cout <<num<<endl;
    }
    return 0;
}
