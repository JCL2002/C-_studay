#include<bits/stdc++.h>
using namespace  std;
int odd,even;
int n;
int main(){
    int t;
    cin >>t;
    while(t--){
        cin >>n;n*=2;
        odd=0;even=0;
        while(n--){
            int tmp;
            cin >>tmp;
            if(tmp&1) odd++;
            else even++;
        }
        if(odd==even)cout <<"Yes"<<endl;
        else cout <<"No"<<endl;
    }
    return 0;
}
