#include<bits/stdc++.h>
using namespace std;
int odd,even;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        odd=0;
        even=0;
        int n;int x;
        cin >>n>>x;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin >>tmp;
            if(tmp&1) odd++;
            else even++;
        }
        if(odd==0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(even>x-1)
        {
            cout <<"YES"<<endl;
            continue;
        }
        else
        {
            if((x-1-even)&1)//���ʣ���ż��ȫ���ϻ���Ҫ�����������͵�����һ��ż��
            {
                if(odd-1>=(x-even)&& even)//ע������ż��������Ϊ��
                {
                    cout <<"YES"<<endl;
                    continue;
                }
                else
                {
                    cout <<"NO"<<endl;
                    continue;
                }
            }
            else//���ż��ȫ���ϣ���ȱż��������һ����
            {
                cout << "YES" <<endl;
                continue;
            }
        }
    }
    return 0;
}
