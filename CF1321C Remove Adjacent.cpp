#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
int a[105], pre[105], nxt[105], vis[105];

int main()
{
	cin >> n;
	cin >> s;
	a[0] = a[n + 1] = -1;
	for (int i = 1; i <= n; ++i)
		a[i] = s[i - 1] - 'a', pre[i] = i - 1, nxt[i] = i + 1;
	int ans = 0;
	for (int i = 25; i; --i)
		for (int nfst = 1; nfst <= 100; ++nfst)
			for (int j = 1; j <= n; ++j)
				if (!vis[j] && a[j] == i && (a[pre[j]] == i - 1 || a[nxt[j]] == i - 1)) {
					vis[j] = 1;
					++ans;
					nxt[pre[j]] = nxt[j];
					pre[nxt[j]] = pre[j];
				}
	cout << ans;
	return 0;
}