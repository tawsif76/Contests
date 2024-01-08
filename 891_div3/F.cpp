#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n + 1];
	map<LL, LL> mp;
	for (int i = 1; i <= n; ++i) cin >> ara[i], mp[ara[i]]++;
	int q; cin >> q;
	
	auto find = [&] (LL b, LL c) {
		LL det = (b * b) - (c * 4);
		if (det < 0) return 0LL;
		LL sqD = sqrt(1.00 * det);
		if ((sqD * sqD) != det or ((b - sqD) % 2 != 0) or ((b + sqD) % 2 != 0)) return 0LL;
		LL a_i = (b - sqD) / 2;
		LL a_j = (b + sqD) / 2;
		if (a_i == a_j) return (mp[a_i] * (mp[a_i] - 1)) / 2;
		return mp[a_i] * mp[a_j];
	};

	while (q--) {
		LL x, y; cin >> x >> y;
		cout << find(x, y) << " ";
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
