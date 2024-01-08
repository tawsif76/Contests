#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	vector<int> ans;
	ans.push_back(ara[1]);
	for (int i = 2; i <= n; ++i) {
		if (ara[i] >= ara[i - 1]) ans.push_back(ara[i]);
		else ans.push_back(ara[i]), ans.push_back(ara[i]);
	}
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
