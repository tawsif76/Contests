#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int a, b, n; cin >> a >> b >> n;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	LL ans = b - 1;
	for (int i = 1; i < n; ++i) ans += min(1 + ara[i], 1LL * a) - 1;
	ans += min(ara[n] + 1, 1LL * a);
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
