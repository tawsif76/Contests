#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int sz = n * (n - 1) / 2;
	map<int, int> mp;
	for (int i = 1; i <= sz; ++i) {
		int x; cin >> x;
		mp[x]++;
	}
	vector<int> v;
	for (auto [u, c]: mp) v.push_back(u);
	v.push_back(v.back());
	for (auto u : v) cerr << u << endl;
	cout << v[0] << " ";
	for (int i = 1; i < (int) v.size() - 1; ++i) {
		cout << v[i] << " ";
		int need = (int) v.size() - i - 1;
		int soFar = need, after = need;
		while (soFar < mp[v[i]]) {
			cout << v[i] << " ";
			after++;
			soFar += after;
		}
	}
	cout << v.back() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
