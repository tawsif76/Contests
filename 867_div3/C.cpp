#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n; cin >> n;
	auto sum = [&] (LL n) {
		return n * (n + 1) / 2;
	};
	cout << sum(n) + sum(n - 2) + 3 * n + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
