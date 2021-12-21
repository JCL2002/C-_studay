#include<bits/stdc++.h>
using namespace std;
int n,m,head,tail;
int arr[2000006];
pair<int,int> q[2000006];
int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> arr[i];
    head=1;
    cout << "0\n";
    for(int i=2;i<=n;i++)
    {
        while((head <= tail) && (q[tail].first >= arr[i-1] )) tail-- ;
        q[++tail].first=arr[i-1];q[tail].second=i-1;
        while(q[head].second < i-m && head < tail) head++;
        cout << q[head].first << "\n";
    }
    return 0;
}
//单调队列模板题目
