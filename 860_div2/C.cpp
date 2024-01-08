#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL __lcm(LL a, LL b) {
	return b / __gcd(a, b) * a;
}

void solve() {
	int n, ans = 1; cin >> n;
	LL gcd = 0, lcm = 1;
	for (int i = 1; i <= n; ++i) {
		LL a, b; cin >> a >> b;
		gcd = __gcd(gcd, a * b);
		lcm = __lcm(lcm, b);
		if (gcd % lcm == 0) continue;
		ans++;
		gcd = a * b, lcm = b;
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
