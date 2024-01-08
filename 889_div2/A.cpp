#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x == i) ans++;
	}
	cout << (ans + 1) / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
