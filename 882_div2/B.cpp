#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	int And = -1;
	for (int i = 1; i <= n; ++i) cin >> ara[i], And &= ara[i];
	if (And) cout << "1\n";
	else {
		int len = 0;
		And = -1;
		for (int i = 1; i <= n; ++i) {
			And &= ara[i];
			if (And == 0) len++, And = -1;
		}
		cout << len << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
