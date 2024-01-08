#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, t; cin >> n >> t;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int best = -1, idx = -1;
	for (int i = 1; i <= n; ++i) {
		if (t >= a[i] and best < b[i]) best = b[i], idx = i;
		--t;
	}
	cout << idx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
