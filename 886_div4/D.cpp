#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	if (n == 1) {
		cout << "0\n";
		return;
	}
	int ans = (int) 2e9, last = 1;
	for (int i = 1; i <= n - 1; ++i) {
		if (ara[i + 1] - ara[i] > k) {
			ans = min(n - (i - last + 1), ans);
			last = i + 1;
		} else if (i == (n - 1)) {
			//cerr << i << " " << last << endl;
			ans = min(n - ((i + 1) - last + 1), ans);
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

