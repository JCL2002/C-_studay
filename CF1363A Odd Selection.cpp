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
            if((x-1-even)&1)//如果剩余的偶数全用上还需要奇数个数，就得少用一个偶数
            {
                if(odd-1>=(x-even)&& even)//注意特判偶数个数不为零
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
            else//如果偶数全用上，还缺偶数个数，一定行
            {
                cout << "YES" <<endl;
                continue;
            }
        }
    }
    return 0;
}
