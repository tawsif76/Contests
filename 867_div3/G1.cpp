#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int cnt[(int) 1e6 + 1];

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	LL ans = 0;
	for (int i = 1; i <= n; ++i) cin >> ara[i], cnt[ara[i]]++;
	for (int i = 1; i <= n; ++i) {
		ans += 1LL * (cnt[ara[i]] - 1) * (cnt[ara[i]] - 2);
		for (int b = 2; 1LL * ara[i] * b * b <= (int) 1e6; ++b) {
			ans += 1LL * cnt[ara[i] * b] * cnt[ara[i] * b * b]; 
		}
	}
	for (int i = 1; i <= n; ++i) cnt[ara[i]]--;
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
