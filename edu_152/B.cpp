#include <bits/stdc++.h>

using namespace std;
using LL = long long;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.first != p2.first) return p1.first > p2.first;
	return p1.second <= p2.second;
}

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1], mn = INT_MAX;
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	vector<pair<int, int> > vec;  
	for (int i = 1; i <= n; ++i) {
		int New = ara[i] - (k * (ara[i] / k));
		if (ara[i] % k == 0) New = k;
		vec.push_back({New, i});
	}
	//for (auto [u, v] : ms) cerr << u << " " << v << '\n';
	sort(vec.begin(), vec.end(), cmp);
	for (auto [u, v] : vec) cout << v << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
