#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, limit; cin >> n >> limit;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	LL lo = 0, hi = (int) 2e9 + 1;
	
	auto chk = [&] (LL h) {
		LL need = 0;
		for (int i = 1; i <= n; ++i) {
			need += 1LL * max(h - ara[i], 0LL);
		}
		return need <= limit;
	};

	while (lo < hi) {
		LL mid = (lo + hi + 1) >> 1;
		if (chk(mid)) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}