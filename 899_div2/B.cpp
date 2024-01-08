#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int q; cin >> q;
	set<int> s;
	vector<vector<int > > v;
	while (q--) {
		int n; cin >> n;
		vector<int> cur;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			s.insert(x);
			cur.push_back(x);
		}
		v.push_back(cur);
	}
	int ans = 0;
	for (int cand : s) {
		set<int> h;
		for (int i = 0; i < (int) v.size(); ++i) {
			bool ok = 0;
			for (int m : v[i]) ok |= m == cand;
			if (!ok) {
				for (int m : v[i]) h.insert(m);
			} 
		}
		ans = max(ans, (int) h.size());
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