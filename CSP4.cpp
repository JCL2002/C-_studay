#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int belong;
    int data;
    bool occupy;
};
node disk[10005];
int ins(int id,int l,int r,int x)
{
    for(int i=l;i<=r;i++)
    {
        if(disk[i].belong==id || disk[i].occupy==0) disk[i].belong=id,disk[i].data=x,disk[i].occupy=1;
        else return i-1;
    }
    return r;
}
bool del(int id,int l,int r)
{
    bool check=1;
    for(int i=l;i<=r;i++) if(disk[i].belong!=id || disk[i].occupy==0) {check=0;break;}
    if(!check) return 0;
    for(int i=l;i<=r;i++) disk[i].occupy=0;
    return 1;
}
bool recover(int id,int l,int r)
{
    bool check = 1;
    for(int i=l;i<=r;i++) if(disk[i].belong!=id || disk[i].occupy){check=0;break;}
    if(!check) return 0;
    for(int i=l;i<=r;i++) disk[i].occupy=1;
    return 1;
}
pair<int,int> read(int p)
{
    if(disk[p].occupy) return pair<int,int>{disk[p].belong , disk[p].data};
    else return {0,0};
}
int main()
{
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	int id,l,r,x,op;
    if(k<=2000 && m <=10000)
    {
        for(int i=1;i<=k;i++)
        {
            cin >> op;
        if(op == 0)
        {
            cin >> id >> l >> r >> x;
            int ops= ins(id,l,r,x);
            if(ops <l) cout << -1 << endl;
            else cout << ops << endl;
        }
        if(op == 1)
        {
            cin >> id >> l >> r;
            if(del(id,l,r)) cout << "OK" << endl;
            else cout << "FAIL" << endl;
        }
        if(op == 2)
        {
            cin >> id >> l >> r;
            if(recover(id,l,r)) cout << "OK" << endl;
            else
            {
                cout << "FAIL" << endl;
//                for(int i=l;i<=r;i++) cout << disk[i].belong << " " << disk[i].data << " " << disk[i].occupy << endl;
            }
        }
        if(op == 3)
        {
            cin >> l;
            pair<int,int> res=read(l);
            cout << res.first << " " << res.second << endl;
        }
        }
    }
    else if(n==1)
    {
        return 0;
    }
	return 0;
}
