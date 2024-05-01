#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n];
	for (int i = 0; i < n; ++i) cin >> ara[i];

	auto calc = [&] (LL x, LL y, LL z) {
		LL tot = x + y + z;
		if (tot % 3 == 0) return z;
		if ((tot + 1) % 3 == 0) return z + 1;
		return z + 2;
	};

	LL ans = (LL)1e18;

	for (int A = 0; A < 3; ++A) {
		for (int B = 0; B < 3; ++B) {
			LL cur = 0;
			vector<LL> v(n);
			v[0] = ara[0] + A, v[1] = ara[1] + B;
			for (int i = 2; i < n; ++i) {
				LL newVal = calc(v[i - 2], v[i - 1], ara[i]);
				v[i] = newVal;
				cur += newVal - ara[i];
			}
			ans = min(ans, cur + A + B);
		}
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
