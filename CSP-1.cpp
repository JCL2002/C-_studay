#include<bits/stdc++.h>
using namespace std;
int n,N;
int arr[203];
long long sum;
int main()
{
	cin.sync_with_stdio(false);
	cin >> n >> N;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=2;i<=n;i++)
    {
        sum+=(i-1)*(arr[i]-arr[i-1]);
    }
    sum+=(N-arr[n]) * n;
    cout << sum;
	return 0;
}
