#include <bits/stdc++.h>
using namespace std;
int T, case_;
int n, a[200005], r, ans, ansl, ansr;
long long s, sum;
int main()
{
    T = 1;
    cin >> T;
    for (case_ = 1; case_ <= T; case_++)
    {
        cin >> n >> s;
        for(int i=0; i<n; i++) cin >> a[i];
        r = -1;
        sum = 0;
        ans = -1;
        for(int i=0; i<n; i++)
        {
            if (r < i)
                r = i, sum = a[i];
            while (r < n && s + sum >= 0)
            {
                if (r - i + 1 > ans)
                    ans = r - i + 1, ansl = i, ansr = r;
                r++, sum += a[r];
            }
            if (r < n)
                sum -= a[r], r--;
            else
                break;
            sum -= a[i];
        }
        if (ans == -1)
            cout << ans << endl;
        else
            cout << ansl + 1 << ' ' << ansr + 1 << endl;
    }
    return 0;
}
