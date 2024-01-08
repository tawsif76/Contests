#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, k; cin >> n >> k;
	LL ara[n + 1], mx = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		mx = max(mx, ara[i]);

	}

	auto ok = [&] (LL big) {
		for (int i = 1; i <= n; ++i) {
			//a_i = big
			LL put = big, need = 0, f = 0;
			for (int j = i; j <= n; ++j) {
				if (ara[j] >= put) { f = 1; break; }
				need += put - ara[j];
				put--;
			}
			if (f and need <= k) return true;
		}
		return false;
	};

	LL lo = mx, hi = (int) 2e8 + 1;
	while (lo < hi) {
		LL mid = (lo + hi + 1) >> 1;
		if (ok(mid)) lo = mid;
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
