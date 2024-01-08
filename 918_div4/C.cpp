#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL tot = 0;
	for (int i = 1; i <= n; ++i) {
		LL x; cin >> x;
		tot += x;
	}

	LL sq = sqrt(1.00 * tot);
	if (sq * sq == tot) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
