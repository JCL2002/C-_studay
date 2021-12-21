#include<bits/stdc++.h>
using namespace std;
int t,n;
int arr[50];
int dp[50];
int ans[50];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> arr[i],dp[i]=1,ans[i]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                dp[i]=max(dp[i],(arr[i]>=arr[j])*(dp[j]+1));
            }
            bool flag=0;
            for(int j=1; j<i; j++)
            {
                if(dp[i]==dp[j]+1 && arr[i]>=arr[j]) ans[i]+=ans[j],flag=1;
            }
            if(flag)ans[i]--;
        }
        int mmax=0;
        for(int i=1;i<=n;i++) mmax=max(mmax,dp[i]);
        int times=0;
        for(int i=1;i<=n;i++) if(dp[i]==mmax) times+=ans[i];
        cout << mmax << " " << times << endl;
    }
    return 0;
}
