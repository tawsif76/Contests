#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	s = "#" + s;
	int l[k + 1], r[k + 1], pre[n + 2]{};
	for (int i = 1; i <= k; ++i) cin >> l[i];
	for (int i = 1; i <= k; ++i) cin >> r[i];
	int q; cin >> q;
	
	auto getId = [&] (int x) {
		return upper_bound(l + 1, l + k + 1, x) - l - 1;
	};

	while (q--) {
		int x; cin >> x;
		int ub = getId(x);
		int L = min(x, l[ub] + r[ub] - x), R =  max(x, l[ub] + r[ub] - x);
		pre[L] += 1;
		pre[min(l[ub] + ((r[ub] - l[ub]) / 2) + 1, R + 1)] -= 1; 
	}
	for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
	for (int i = 1; i <= n; ++i) {
		if (pre[i] % 2 == 0) continue;
		int ub = getId(i);
		int comp = r[ub] - (i - l[ub]);
		swap(s[i], s[comp]);
	}

	cout << s.substr(1, n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
