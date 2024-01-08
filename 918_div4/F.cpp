#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using LL = long long;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;
void solve() {
	int n; cin >> n;
	vector<int> v;
	vector<pair<int, int > > range;
	for (int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
		range.push_back({r, l});
		v.push_back(l);
		v.push_back(r);
	}
	LL ans = 0;
	o_set processed;
	sort(range.begin(), range.end());
	for (auto [r, l] : range) cerr << r << " " << l << endl;
	for (int i = n - 1; i >= 0; --i) {
		auto [R, L] = range[i];
		cerr <<  processed.order_of_key(R) << endl;
		ans += processed.order_of_key(R);
		processed.insert(L);
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
