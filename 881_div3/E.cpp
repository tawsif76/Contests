#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	int l[m + 1], r[m + 1], q;
	for (int i = 1; i <= m; ++i) cin >> l[i] >> r[i];
	cin >> q;
	int qry[q + 1];
	for (int i = 1; i <= q; ++i) cin >> qry[i];
	int lo = 1, hi = q + 1, pos = 0;
	while (lo < hi) {
		int mid = lo + hi >> 1;
		int pre[n + 1]{};
		for (int i = 1; i <= mid; ++i) pre[qry[i]] = 1;
		for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
		bool ok = 0;
		for (int i = 1; i <= m; ++i) {
			int tot = r[i] - l[i] + 1;
			int one = pre[r[i]] - pre[l[i] - 1];
			if (one > tot - one) { ok = 1; break; }
		}
		if (ok) hi = mid;
		else lo = mid + 1;
	}
	if (hi > q) hi = -1;
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
