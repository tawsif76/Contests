#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1], rt = -1, lt = n + 1, lk = 0, rk = 0; 
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (ara[i] == ara[1] and lk < k) lk++, rt = i;
	}
	for (int i = n; i >= 1; --i) {
		if (ara[i] == ara[n] and rk < k) rk++, lt = i;  
	}
	if (lk != k or rk != k or (rt > lt and ara[1] != ara[n])) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
