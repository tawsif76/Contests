#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int o = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] & 1) o++;
	}
	if (o & 1) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
