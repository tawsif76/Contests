#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		ans += a - b > 0;
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
