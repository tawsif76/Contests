#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	int k; cin >> k;
	vector<pair<int, int > > v;
	int vx, vy; cin >> vx >> vy;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		v.push_back({x, y});
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int tv = abs(i - vx) + abs(j - vy);
			for (auto [l, r] : v) {
				int tx = abs(l - i) + abs(r - j);
				if (tx == tv) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
