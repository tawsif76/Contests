#include <bits/stdc++.h>

using namespace std;
using LL = long long;

bool cmp(const tuple<int, LL, int> &t1, const tuple<int, LL, int> &t2) {
	if (get<0>(t1) == get<0>(t2)) {
		if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
		return get<2>(t1) <= get<2>(t2);
	} else return get<0>(t1) > get<0>(t2);
}
void solve() {
	int n, m, h; cin >> n >> m >> h;
	vector<vector<int>> v(n , vector<int> (m)); 
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> v[i][j];
	for (int i = 0; i < n; ++i) sort(v[i].begin(), v[i].end());
	vector<tuple<int, LL, int > > ord;
	for (int i = 0; i < n; ++i) {
		LL tot = 0, penalty = 0;
		int p = 0;
		for (int j = 0; j < m; ++j) {
			if (tot + v[i][j] <= h) {
				p++, tot += v[i][j];
				penalty += tot;
			}
		}
		ord.push_back({p, penalty, i});
	}
	int ans = 1;
	sort(ord.begin(), ord.end(), cmp);
	for (auto [x, y, z] : ord) {
		//cerr << x << " " << y << " " << z << endl;
		if (z == 0) {
			cout << ans << "\n";
			return;
		}
		ans++;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}