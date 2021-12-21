#include<bits/stdc++.h>
using namespace std;
int t,n;
int a,b,c,d;
int main()
{
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >>a >> b >> c >> d;
        while(a%10 ==0 ) b++,a/=10;
        while(c%10 ==0 ) d++,c/=10;
        if(a==c && b==d)
        {
            cout << "=\n";
        }
        else
        {
            int A=a,C=c;
            int len_a=b,len_b=d;
            while(A) len_a++,A/=10;
            while(C) len_b++,C/=10;
            if(len_a==len_b)
            {
                while(b<d) c*=10,d--;
                while(b>d) a*=10,b--;
//                cout << "debug " <<a << "  " << c <<endl;
                if(a>c) cout << ">\n";
                else cout << "<\n";
            }
            else
            {
                if(len_a>len_b) cout << ">\n";
                else cout << "<\n";
            }
        }
    }
    return 0;
}
