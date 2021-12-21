#include<bits/stdc++.h>
using namespace std;
int n,m,fa[5000],sum,u,v,w,num;
int Find(int x) {
    if(x!=fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}
void Union(int a,int b) {
    int ra=Find(a),rb=Find(b);
    fa[ra]=rb;
}
priority_queue< pair< int , pair<int,int> > , vector< pair< int, pair<int,int> > > ,greater< pair< int , pair<int,int> > > > q;
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) cin >> u >> v >> w , q.push( { w, {u,v} } );
    for(;!q.empty();q.pop()) if( Find( q.top().second.first ) != Find( q.top().second.second ) ) sum+=q.top().first,num++,Union( q.top().second.first , q.top().second.second );
    if(num<n-1) cout << "false" ;
    else cout << sum;
    return 0;
}
