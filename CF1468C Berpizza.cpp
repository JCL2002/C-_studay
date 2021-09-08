#include<bits/stdc++.h>
using namespace std;
struct node
{
    int i;//´ÎÐò
    int m;
    bool operator>(node a) const
    {
        if(m>a.m) return 1;
        else if(m<a.m) return 0;
        else
        {
            return i<a.i;
        }
    }
    bool operator<(node a) const
    {
        if(m<a.m) return 1;
        else if(m>a.m) return 0;
        else
        {
            return i>a.i;
        }
    }
};
bool I[500005];
int j;
priority_queue< node , vector< node >  > q;
int n;
int main()
{
    j=1;
    int index=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin >> op ;
        if(op==1)
        {
            index++;
            int tmp;
            cin >> tmp ;
//            cout << "yes" <<endl;
            q.push(node{index,tmp});
//            cout << "ok" <<endl;
        }
        else if(op==2)
        {
            while(I[j]) j++;
            cout << j << endl;
            I[j]=1;
        }
        else
        {
            while(I[q.top().i]) q.pop();
            cout << q.top().i << endl;
            I[q.top().i]=1;
            q.pop();
        }
    }
    return 0;
}
