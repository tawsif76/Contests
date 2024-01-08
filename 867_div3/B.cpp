#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<int> pos, neg;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x >= 0) pos.push_back(x);
		else neg.push_back(x);
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());
	LL ans = LLONG_MIN;
	if ((int) neg.size() >= 2) ans = max(ans, 1LL * neg[0] * neg[1]);
	if ((int) pos.size() >= 2) ans = max(ans, 1LL * pos[0] * pos[1]);
	if (n == 2 and (int) pos.size() == 1) ans = 1LL * pos[0] * neg[0];
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
