#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	if (n & 1) {
		if (n == 9 or n <= 5) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << "1 2 " << n - 3 << "\n";
		}
	} else {
		if (n <= 6) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << "1 5 " << n - 6 << "\n";
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
