#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	int idx = -1;
	for (int i = n; i >= 2; --i) {
		if (ara[i] >= ara[i - 1]) continue;
		else {
			idx = i;
			break;
		}
	}
	int mx = -1;
	for (int i = 1; i < idx; i++) mx = max(mx, ara[i]);
	cout << max(mx, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
