#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		if (n % i == 0) ans++;
		else break; 
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
