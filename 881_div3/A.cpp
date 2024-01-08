#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	int i = 1, j = n, ans = 0;
	while (i <= j) {
		ans += ara[j] - ara[i];
		i++, --j;
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
