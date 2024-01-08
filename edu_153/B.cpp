#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL m, k, a1, bk; cin >> m >> k >> a1 >> bk;
	if (bk * k + a1 >= m) cout << "0\n";
	else {
		m -= a1;
		m -= k * bk;
		LL ans = m;

	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
