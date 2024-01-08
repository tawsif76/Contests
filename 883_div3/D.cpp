#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	double base, h; cin >> base >> h;
	double ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	double ans = 0;

	auto trapzm = [&] (double i, double j) {
		return 0.5 * (i + base) * j;
	};

	auto tri = [&] () {
		return 0.5 * base * h;
	};

	ans = tri();
	for (int i = 1; i <= n - 1; ++i) {
		double dif = ara[i + 1] - ara[i];
		if (ara[i] + h > ara[i + 1]) {
			double side = ((ara[i] + h - ara[i + 1]) * base) / (2.00 * h);
			ans += trapzm(side * 2.00, ara[i + 1] - ara[i]);
		} else ans += tri();
	}
	cout << fixed << setprecision(6) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
