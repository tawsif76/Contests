#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, m, k, h; cin >> n >> m >> k >> h;
	LL ara[n  + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		bool ok = 0;
		for (int j = 1; j <= m; ++j) {
			for (int l = 1; l <= m; ++l) {
				if (l == j) continue;
				if (abs((k * j) - (l * k)) == abs(h - ara[i])) {
					// if (ara[i] == 11) {
					// 	cerr << k * j << " " << l * k << "\n";
					// }
					ok = 1;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) {
			//cerr << ara[i] << "\n";
			ans++;
		}
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
