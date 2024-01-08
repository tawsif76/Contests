#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	ara[0] = 0;
	bool ok = 1;
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++i) cin >> ara[i], ok &= (ara[i] >= ara[i - 1]);
	if (ok) {
		for (int i = 2; i <= n; ++i) {
			int med = (ara[i] + ara[i - 1]) / 2;
			ans = min(ans, abs(ara[i - 1] - med) + 1);
		}
	}
	if (!ok) ans = 0;
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
