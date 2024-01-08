#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int ans = -1, mul = 1, zero = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] != 0) mul *= ara[i];
		zero += ara[i] == 0;
	}
	if (zero >= 2) {
		cout << "0\n";
		return;
	} else if (zero == 1) {
		cout << mul << "\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, (mul / ara[i]) * (ara[i] + 1));
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
