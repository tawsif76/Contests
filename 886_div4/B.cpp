#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<pair<int, int > > v;
	for (int i = 0; i < n; ++i) {
		int sz, q; cin >> sz >> q;
		if (sz <= 10) v.push_back({q, i + 1});
	}
	sort(v.rbegin(), v.rend());
	cout << v[0].second << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
