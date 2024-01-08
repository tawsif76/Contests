#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<pair<int, int > > v;
	while (n--) {
		int m; cin >> m;
		int ara[m + 1];
		for (int i = 1; i <= m; ++i) cin >> ara[i];
		sort(ara + 1, ara + m + 1);
		v.push_back({ara[2], ara[1]});
	}
	sort(v.rbegin(), v.rend());
	LL sum = 0;
	int mn = INT_MAX;
	for (int i = 0; i < (int) v.size() - 1; ++i) sum += v[i].first, mn = min(mn, v[i].second);
	mn = min(mn, v.back().second); 
	cout << sum + mn << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
