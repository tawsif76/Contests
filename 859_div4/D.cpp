#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, q; cin >> n >> q;
	LL ara[n + 1]{};
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		ara[i] += ara[i - 1];
	}
	while (q--) {
		int l, r; cin >> l >> r;
		LL k; cin >> k;
		LL sum = ara[n] - (ara[r] - ara[l - 1]) + k * (r - l + 1);
		if (sum & 1) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
