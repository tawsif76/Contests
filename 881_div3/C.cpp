#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n; cin >> n;
	LL ans = 0;
	while (n) {
		ans += n;
		n /= 2;
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
