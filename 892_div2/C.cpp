#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		vector<int> v;
		for (int j = 1; j <= i; ++j) v.push_back(j);
		for (int j = n; j >= i + 1; --j) v.push_back(j);
		int f = 0, s = 0;
		for (int k = 0; k < n; ++k) f += (k + 1) * v[k], s = max(s, (k + 1) * v[k]);
		ans = max(ans, f - s);
	}
	if (n == 2) ans = 2;
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
