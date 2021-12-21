#include<bits/stdc++.h>
using namespace std;
const int maxn = 4005;
long long num[maxn];
long long f[maxn];
long long n;
bool flag(long long l,long long r)
{
	int t=0;
	int nn[maxn];
	nn[4]=num[r];
	for(int i=l;i<r;i++)
	{
		nn[++t]=num[i];
		for(int j=l;j<r;j++)
		{
			if(j==i)continue;
			nn[++t]=num[j];
			for(int k=l;k<r;k++)
			{
				if(k==j||k==i)continue;
				nn[++t]=num[k];
				if((nn[1]==nn[2]&&nn[3]==nn[4])||((nn[1]==nn[4]&&nn[2]==nn[3])||(nn[1]==nn[3]&&nn[2]==nn[4])))return true;
				t--;
			}
			t--;
		}
		t--;
	}
	return false;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&num[i]);
	f[0]=0;
	long long last=1;
	for(int i=1;i<=n;i++)
	{
		if(i-last+1>=4)
		{
			if(flag(last,i))
			{
				f[i]=max(f[i],f[last-1]+1);
				last=i+1;
			}
			else f[i]=f[i-1];
		}
		else f[i]=f[i-1];
	}
	cout<<f[n];
}
