#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) cin >> ara[i], sum += ara[i];
	for (int i = 1; i <= n; ++i) {
		int cur = sum - ara[i] + (-ara[i]);
		if (cur % 2 == 0) ans++;
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
