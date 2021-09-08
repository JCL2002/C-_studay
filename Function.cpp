#include<bits/stdc++.h>
using namespace std;
#define int long long
int g(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int x,A,B,C,D,N;
int I;
signed main(){
    int t;
    cin >>t;
    while(t--){
        cin >>A>>B>>C>>D>>N;
        int mmin=1e18+7;
        for(int i=1;i<=N;i++){
            if(A*i*i*g(i)+B*i*i+C*i*g(i)*g(i)+D*i*g(i)<mmin){
                mmin=A*i*i*g(i)+B*i*i+C*i*g(i)*g(i)+D*i*g(i);
                I=i;
            }
//            mmin=min(mmin,A*i*i*g(i)+B*i*i+C*i*g(i)*g(i)+D*i*g(i));
        }
        cout <<mmin<<endl;
        cout <<I<<endl;
    }

    return 0;
}
