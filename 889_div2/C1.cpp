#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int sumP = 0, sumN = 0, mxP = -1, idxp = -1, mxN = INT_MAX, idxn = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] >= 0) {
			if (mxP < ara[i]) {
				mxP = ara[i];
				idxp = i;
			}
			sumP += ara[i];
		}
		else {
			if (mxN > ara[i]) {
				mxN = ara[i];
				idxn = i;
			}
			sumN += ara[i];
		}
	}
	vector<pair<int, int > > v;
	if (sumP >= abs(sumN)) {
		
		for (int i = 1; i <= n; ++i) {
			if (ara[i] < 0) {
				while (ara[i] < 0) {
					ara[i] += mxP;
					v.push_back({i, idxp});
				}
			}
		}
		for (int i = 2; i <= n; ++i) {
			if (ara[i] >= ara[i - 1]) continue;
			ara[i] += ara[i - 1];
			v.push_back({i, i - 1});
		} 
	} else {
		for (int i = 1; i <= n; ++i) {
			if (ara[i] > 0) {
				while (ara[i] > 0) {
					ara[i] += mxN;
					v.push_back({i, idxn});
				}
			}
		}
		for (int i = n - 1; i >= 1; --i) {
			if (ara[i] <= ara[i + 1]) continue;
			ara[i] += ara[i + 1];
			v.push_back({i, i + 1});
		}
	}
	bool ok = 1;
	for (int i = 2; i <= n; ++i) {
		ok &= (ara[i] >= ara[i - 1]);
	}
	// cerr << ok << '\n';
	assert((int) v.size() <= 50);
	cout << v.size() << "\n";
	for (auto [i, j] : v) cout << i << " " << j << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
