#include<bits/stdc++.h>
using namespace std;
int t,n;
int tree[200005];//����ĳ���ڵ�ĸ��ڵ�
int p[200005];//Ҫ�������վ�������������˳��
int tall[200005];//����ĳ���ڵ㵽���ڵ�ľ���
int ans[200005];//��¼�𰸣��ߵĳ��ȣ�
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
            if(tree[i]==i) root=i;//Ѱ�Ҹ��ڵ�
            tall[i]=-1;
        }
        for(int i=1;i<=n;i++) cin >> p[i];
        tall[root]=0;//���ڵ�ľ�����0
        ans[root]=0;
        if(p[1]!=root)//�����еĵ�һ�����Ȼ��root����
        {
            cout << -1 << endl;
            continue;
        }
        bool flag=1;
        for(int i=2;i<=n;i++)//���Ĵ���
        {
            if( tall[ tree[ p[i] ] ] <0 )//���ڵ�i��������˵��p[i] �ĸ��ڵ�����p[i]�����Ҫ��������[1,i)���Ѿ����ֹ����У���Ϊ�������������ڵ���ӽڵ��Զ
            {
                flag=0;//����ì��
                break;
            }
            else
            {
                ans[ p[i] ] = i- tall[ tree[ p[i] ] ];//��¼�𰸣������i�����ֵĵ������ڵ�ľ������i����ô�������ߵĳ��Ⱦ͵���  i-���ڵ�[ p[i] ] (����i-tall[ tree[ p[i] ] ])
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
