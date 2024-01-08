#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (i == j or k == j or k == i) continue;
				for (int b = 1; b <= 1000; ++b) {
					if (((ara[i] * b) == ara[j]) and ((ara[j] * b) == ara[k])) {
						ans++;
						cerr << i << " " << j << " " << k << endl;
					}
				}
			}
		}
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
