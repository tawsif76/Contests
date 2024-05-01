#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int fre[n + 1]{}, occ[n + 1]{};
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (!occ[x]) fre[i]++, occ[x] = 1;
		else fre[i]--, occ[x] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		fre[i] += fre[i - 1];
		ans = max(ans, fre[i]);
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
