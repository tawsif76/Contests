#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	char ara[n + 1][m + 1];
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) cin >> ara[i][j];
	int k = 0;
	string cur = "vika";
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (ara[j][i] == cur[k]) {
				k++;
				break;
			}
		}
	}
	if (k >= 4) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
