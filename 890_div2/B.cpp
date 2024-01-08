#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int one = 0, non = 0;
	for (int i = 1; i <= n; ++i) cin >> ara[i], one += (ara[i] == 1);
	non = n - one;
	if (n == 1) cout << "NO\n";
	else if (non >= one) cout << "YES\n";
	else {
		LL same = one - non;
		for (int i = 1; i <= n; ++i) {
			if (ara[i] != 1) {
				same -= 1LL * (ara[i] - 2);
			}
		}
		if (same <= 0) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
