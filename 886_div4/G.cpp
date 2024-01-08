#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	map<int, int> mp, np, xp, yp;
	vector<pair<int, int > > v;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		v.push_back({x, y});
		xp[x]++;
		yp[y]++;
		mp[y - x]++;
		np[y + x]++;
	}	
	LL ans = 0;
	for (auto [x, y] : v) {
		if (mp[y - x]) ans += mp[y - x], --ans;
		if (np[x + y]) ans += np[x + y], --ans;
		if (xp[x]) ans += xp[x], --ans;
		if (yp[y]) ans += yp[y], --ans;
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
