#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	LL j[n + 1], g[m + 1];
	for (int i = 1; i <= n; ++i) cin >> j[i];
	for (int i = 1; i <= m; ++i) cin >> g[i];
	sort(j + 1, j + n + 1);
	sort(g + 1, g + m + 1);
	LL ans = 0;
	if (k & 1) {
		if (g[m] > j[1]) swap(j[1], g[m]);
		for (int i = 1; i <= n; ++i)  ans += 1LL * j[i];
	} else {
		if (j[1] < g[m]) swap(j[1], g[m]);
		sort(j + 1, j + n + 1);
		sort(g + 1, g + m + 1);
		if (j[n] > g[m]) swap(j[n], g[1]);
		for (int i = 1; i <= n; ++i) ans += 1LL * j[i];
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
