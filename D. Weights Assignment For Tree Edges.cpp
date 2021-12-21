#include<bits/stdc++.h>
using namespace std;
int t,n;
int tree[200005];//树上某个节点的父节点
int p[200005];//要求树按照距离树根的排列顺序
int tall[200005];//树上某个节点到根节点的距离
int ans[200005];//记录答案（边的长度）
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int root;
        for(int i=1;i<=n;i++)
        {
            cin >> tree[i];
            if(tree[i]==i) root=i;//寻找根节点
            tall[i]=-1;
        }
        for(int i=1;i<=n;i++) cin >> p[i];
        tall[root]=0;//根节点的距离是0
        ans[root]=0;
        if(p[1]!=root)//排列中的第一个点必然是root才行
        {
            cout << -1 << endl;
            continue;
        }
        bool flag=1;
        for(int i=2;i<=n;i++)//核心代码
        {
            if( tall[ tree[ p[i] ] ] <0 )//对于第i个排列来说，p[i] 的父节点必须比p[i]距离根要近，即在[1,i)中已经出现过才行，因为不可能做到父节点比子节点更远
            {
                flag=0;//出现矛盾
                break;
            }
            else
            {
                ans[ p[i] ] = i- tall[ tree[ p[i] ] ];//记录答案：假设第i个出现的点距离根节点的距离就是i，那么，这条边的长度就等于  i-父节点[ p[i] ] (即：i-tall[ tree[ p[i] ] ])
                tall[ p[i] ] =i;
            }
        }
        if(flag)
        {
            for(int i=1;i<=n;i++) cout << ans[ i ] << " ";
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
