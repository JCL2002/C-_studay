#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[5009];
long long solve(int l,int r,long long high){
    if(l==r) return 1;
    long long ans,mn=-1,tmp=r-l+1;
    for(int i=l;i<=r;i++)
    	if(mn==-1 || mn>arr[i]) mn=arr[i];
    ans=mn-high;
    for(int i=l;i<=r;i++)
	{
        int pos;
        if(arr[i]==mn) continue;
        for(int j=i;j<=r;j++)
		{
            pos=j;
            if(j==r || arr[j+1]==mn) break;
        }
        ans+=solve(i,pos,mn);
        i=pos+1;
    }
    return min(tmp,ans);
}
int main()
{
    cin.sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin >> arr[i];
	cout << solve(1,n,0);
	return 0;
}
