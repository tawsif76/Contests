#include <bits/stdc++.h>

using namespace std;
using LL = unsigned long long;

void solve() {
	LL x; cin >> x;
	LL lo = 1, hi = 2648956422;
	while (lo < hi) {
		LL mid = (lo + hi) >> 1;
		LL n = mid * mid - mid;
		if (n > x * 2) hi = mid;
		else lo = mid + 1;
	}
	LL sol = hi;
	LL cover = sol * (sol - 1) / 2;
	if (cover == x) cout << sol << "\n";
	else {
		--sol;
		cover = sol * (sol - 1) / 2;
		cout << sol + x - cover << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
