/*
* どこへ佩くかわからないけど、暴はもう祇にいる
             =@.
             @@@`
            .@@@@^                ..
            .@@@@@\]]`.      .]@@@@`
             @@@@@@@@@@@@@@@@@@@@@.
          ./@@@@@@@@@@@@@@@@@@@@/
         =@@@@@^,]\@@@@@@[@@@@@^
   .]],[[@@@@@@@/O@@@@@\=@\@@@@@^
    .]/[..@@@@@@@@@@@@@@@@@@@@@@@.
           ,\@@@@@@@@@@@@@@@@@@/\.
              .[\@@@@@@@@@@@[..\` ..     .]].
                  =@@@@@^        ,`     /.  .\
                  =@@@@@@^             .@@`  =^
                  =@@@@@@@^              .   =.
                  \^=@@@@@@\                ,`
                  =@@@@@@@@@@`             /.
                  =@@@@@@@@@@@\          ]`
                  =/@@@@@@@@@@@@\     ./.
                  =\=@@@@@@@@@@@@@^ ,/
                  =^.@@@@@@@@@@@@@@@`
                  =^ @.\@@@@@@@@@@@@
                ,]@.`@^ .\@@@@@@@@@^
                ,[`[[[.,\@@@@@@@[[.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define Sum(a) (accumulate (all(a), 0ll))
#define debug(...) {string __t(#__VA_ARGS__);___debug(__t,count(all(__t),','), __VA_ARGS__);}
#define MR Miller_Rabbin
#define PR Pollard_Rho
#define inf 2e18
#define PI 3.1415926535898
template<class T>void ___debug(string s, int args,T ...) {
    va_list ap; T t; args++; va_start(ap, args); int c = 0; char d;
    if (args == 1) {cout << s << " is " << va_arg(ap, T) << endl;return;}
    cout << "\n----debug---start----\n";
    for (int i = 0; i < args; ++i) {t = va_arg(ap, T);
    while (s[c] != ',' && s[c] != '\0') { d = s[c++]; if (d != ' ')cout << d; }
        cout << " is "; cout << t << endl; c++;}
    cout << "----debug---end----\n";va_end(ap);}
void __go() {
    //srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i;        return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
inline ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down
template<class T> inline T qmul(T a, T b, T mod) { a %= mod; T res = 0; while (b != 0) { if (b & 1)res = (res + a) % mod; a = (a + a) % mod; b >>= 1; } return res; }
inline ll qmul(ll a, ll b, ll mod) { return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod; }
//template<class T> T qpow(T a, T b, T mod) { T res = 1; while (b != 0) { if (b & 1) res = qmul(res, a, mod); a = qmul(a, a, mod); b >>= 1; }return res; }
template<class T> T qpow(T a, T b, T mod) { T res = 1; while (b != 0) { if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1; }return res; }
template<class T> inline T gcd(T __m, T __n) { T __t; while (__n != 0) { __t = __m % __n; __m = __n; __n = __t; }return __m; }
template<class T> void Exgcd(T a, T b, T& x, T& y) { if (b == 0) x = 1, y = 0; else Exgcd(b, a % b, y, x), y -= a / b * x; }
const int dx[4]{ 1,0,-1,0 }, dy[4]{ 0,1,0,-1 }; // for every grid problem!!
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
int mod = 998244353;
int n, m;
set<pii> ans;
bool va(int x, int y) {
    return (x >= 0 && y >= 0 && x < n&& y < m);
}
void dfs(int x, int y, vector<vector<bool>>& vis, vector<string>& s) {
    int cnt = 0;
    int a, b;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (va(xx, yy) && s[xx][yy] == '.') {
            if (vis[x][y])continue;
            cnt++; a = xx, b = yy;
        }

    }
    if (cnt > 1)return;
    else {
        ans.insert(mkp(x, y));
        s[x][y] = '+';
        vis[x][y] = 1;
        if(cnt==1)
            dfs(a, b, vis, s);
    }
}

signed main()
{
    __go();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans.clear();
        vector<string> s(n);
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        cin >> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'L') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (va(x,y) && s[x][y] != '#') {
                            dfs(x, y, vis, s);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ans.count(mkp(i, j)))cout << '+';
                else cout << s[i][j];
            }cout << endl;
        }
    }
    return 0;

}
