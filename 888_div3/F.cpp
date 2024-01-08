#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<pair<int, int > > v;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());
	int mnXor = INT_MAX, idx1 = -1, idx2 = -1, x = -1;
	for (int i = 0; i < n - 1; ++i) {
		if ((v[i].first ^ v[i + 1].first) < mnXor) {
			idx1 = v[i].second, idx2 = v[i + 1].second;
			mnXor = v[i].first ^ v[i + 1].first;
			x = (v[i].first ^ ((1 << k) - 1)) & (v[i + 1].first ^ ((1 << k) - 1));
		}
	}
	cout << idx1 << " " << idx2 << " " << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
