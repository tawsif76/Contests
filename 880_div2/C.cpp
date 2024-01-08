#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int pw[7];

void solve() {
	int a, b, c; cin >> a >> b >> c;
	LL k; cin >> k;
	for (int curA = pw[a - 1]; curA < pw[a]; ++curA) {
		LL L = max(pw[b - 1], pw[c - 1] - curA);
		LL R = min(pw[b] - 1, pw[c] - 1 - curA);
		if (R < L) continue;
		if (k <= R - L + 1) {
			cout << curA << " + " << L + k - 1 << " = " << L + k - 1 + curA << "\n";
			return;
		}
		k -= (R - L + 1);
	}
	cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i <= 6; ++i) pw[i] = pw[i - 1] * 10;
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
