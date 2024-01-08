#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int m; cin >> m;
	map<int, vector<int > > v;
	for (int i = 1; i <= m; ++i) {
		int n; cin >> n;
		for (int j = 1; j <= n; ++j) {
			int x; cin >> x;
			v[x].push_back(i);
		}
	}
	vector<int> ans(m + 1, -1);
	for (auto [x, y] : v) {
		if (ans[y.back()] == -1) ans[y.back()] = x;
	}
	bool ok = 1;
	for (int i = 1; i <= m; ++i) if (ans[i] == -1) ok = 0;
	if (!ok) cout << "-1\n";
	else {
		for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
