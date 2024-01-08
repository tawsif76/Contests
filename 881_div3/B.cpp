#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n + 1], sum = 0;
	for (int i = 1; i <= n; ++i) cin >> ara[i], sum += abs(ara[i]);
	int op = 0;
	for (int i = 1; i <= n; ) {
		int j = i, ok = 0;
		while (j <= n and ara[j] <= 0) ok |= (ara[j] < 0), j++;
		if (ok) op++;
		if (i == j) i++;
		else i = j;
	}
	cout << sum << " " << op << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
