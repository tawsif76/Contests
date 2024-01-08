#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k, q; cin >> n >> k >> q;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];

	int last = 0;
	
	auto sum = [&](LL v) {
		return (v * (v + 1)) / 2;
	};

	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ara[i] > q or i == n) {
			LL cnt = i - last - 1;  
			if (i == n and ara[i] <= q) cnt++;
			if (cnt >= k) {
				LL seg = cnt - k + 1;
				LL curAns = seg * cnt - seg * k - sum(seg - 1) + seg;
				cerr << curAns << endl;
				ans += curAns;
			}
			last = i;
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
