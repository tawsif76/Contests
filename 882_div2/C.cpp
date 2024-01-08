#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1], pre[n + 1]{};
	for (int i = 1; i <= n; ++i) cin >> ara[i], pre[i] = pre[i - 1] ^ ara[i];
	for (int cand = (1 << 8) - 1; cand >= 0; --cand) {
		bool has[260]{};
		has[0] = 1;
		for (int i = 1; i <= n; ++i) {
			int complement = cand ^ pre[i];
			if (has[complement]) {
				cout << cand << "\n";
				return;
			}
			has[pre[i]] = 1;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
