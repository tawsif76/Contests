#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<int> odd, oi, even, ei;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x & 1) {
			odd.push_back(x);
			oi.push_back(i);
		} else {
			even.push_back(x);
			ei.push_back(i);
		}
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	int ara[n + 1];
	for (int i = 0; i < (int) odd.size(); ++i) {
		ara[oi[i]] = odd[i];
	}
	for (int i = 0; i < (int) even.size(); ++i) {
		ara[ei[i]] = even[i];
	}
	bool ok = 1;
	for (int i = 1; i < n; ++i) ok &= (ara[i] >= ara[i - 1]);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
