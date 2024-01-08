#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using LL = long long;

void solve() {
	int n; cin >> n;
	LL a[n + 1], b[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	o_set<LL> s;
	map<LL, LL> mp;
	for (int i = 1; i <= n; ++i) {
		LL x = a[i] - b[i];
		mp[x]++;
		s.insert(x);
	}
	// for (auto u : s) cerr << u << "\n";
	set<LL> ans;
	for (int i = 1; i <= n; ++i) {
		LL ser = a[i] - b[i];
		LL cnt = s.order_of_key(ser) + mp[ser];
		if (cnt == n) ans.insert(i);
	}
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
