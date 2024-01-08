#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1];
	bool ok = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] == k) ok = 1;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
