#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        //˼·��ÿһ����ĳ��ȵ�����ȣ���ʹ����Ⱦ����ܶ�
        //ÿһ������ʣ��n-1��������ǰ(n-1)/2����Ϊ��(Ӯ)����(n-1)/2Ϊ�루�䣩������Ϊ����ߣ�ƽ�֣�
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(j<=(n-1)/2)
                {
                    cout <<"1 ";
                }
                else if(j>=(n-(n-1)/2))
                {
                    cout <<"-1 ";
                }
                else cout <<"0 ";
            }
        }
        cout <<endl;
    }
    return 0;
}
