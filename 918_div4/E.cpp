#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	LL pre[n + 1]{};
	for (int i = 1; i <= n; ++i) {
		if (i - 2 >= 1) pre[i] = pre[i - 2] + ara[i];
		else pre[i] = ara[i];
	}
	for (int i = 1; i <= n; ++i) cerr << pre[i] << " \n"[i == n];
	map<LL, bool> mp;
	mp[0] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!mp[(pre[i] - pre[i - 1])]) {
			cerr << i << " " << "\n";
			cout << "YES\n";
			return;
		}
		mp[-(pre[i] - pre[i - 1])] = 1;
	}
	cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
