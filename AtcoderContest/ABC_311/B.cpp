#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	char grid[n + 1][m + 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> grid[i][j];
	}
	int ans = 0, prv = 0;
	for (int i = 1; i <= m; ++i) {
		bool bad = 0;
		for (int j = 1; j <= n; ++j) {
			if (grid[j][i] != 'o') {
				bad = 1;
				break;
			} 
		}
		if (bad) ans = max(ans, prv), prv = 0;
		else prv++;
	}
	ans = max(ans, prv);
	cout << ans << '\n';
 }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
