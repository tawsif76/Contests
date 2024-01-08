#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int e = 0, o = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x & 1) o += x;
		else e += x;
	}
	cout << (e > o ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
