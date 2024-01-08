#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1], rev[n + 1];
	bool ok = 1;
	for (int i = 1; i <= n; ++i) cin >> ara[i], rev[i] = ara[i];
	reverse(rev + 1, rev + n + 1);
	for (int i = 1; i <= n; ++i) {
		int gteq = n - (lower_bound(rev + 1, rev + n + 1, i) - rev) + 1;
		if (gteq != ara[i]) ok = 0;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}