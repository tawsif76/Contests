#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];

	bool dec = 0;
	vector<int> idx = {1};

	for (int i = 2; i <= n; ++i) {
		if (ara[i] >= ara[idx.back()]) {
			if (dec and ara[idx[0]] >= ara[i]) idx.push_back(i);
			else if (!dec) idx.push_back(i);
		} else if (!dec and ara[idx[0]] >= ara[i]) idx.push_back(i), dec = 1;
	}

	vector<bool> ans(n + 1, 0);

	for (int i = 0; i < (int) idx.size(); ++i) ans[idx[i]] = 1;
	for (int i = 1; i <= n; ++i) cout << ans[i];
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
