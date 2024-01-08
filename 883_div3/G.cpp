#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	string sym; cin >> sym;
	vector<string> v, dem;
	for (int mask = 0; mask < (1 << n); ++mask) {
		string s = "";
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) s += "1";// 1 rep has sym
			else s += "0"; 
		}
		v.push_back(s);
		if (s == "00111") dem.push_back(s);
	}
	for (auto u : v) cout << u << endl;
	for (int i = 0; i < m; ++i) {
		string x, y, cur(n, '0'); cin >> x >> y;
		for (int k = 0; k < n; ++k) {
			
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
