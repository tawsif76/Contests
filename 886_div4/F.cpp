#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int fre[n + 2]{};
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x <= n) fre[x]++;
	}
	int ans = 0, track[n + 2]{};
	for (int i = 1; i <= n; ++i) {
		if (!fre[i]) continue;
		for (int j = i; j <= n; j += i) {
			track[j] += fre[i];
		}
	}
	for (int i = 1; i <= n; ++i) ans = max(ans, track[i]);
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
