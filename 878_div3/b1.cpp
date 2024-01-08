#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a, b;
	for (int i = 0; i < k / 2; ++i) a.push_back(1 << i);
	for (int i = k / 2; i < k; ++i) b.push_back(1 << i);
	for (auto u : a) cerr << u << " ";
	cerr << "\n";
	for (auto u : b) cerr << u << " ";
	cerr << endl;
	vector<int> v1, v2;
	int ans = 0;
	for (int mask = 0; mask < (1 << (int) a.size()); ++mask) {
		int sum = 0;
		for (int i = 0; i < (int) a.size(); ++i) {
			if (mask & (1 << i)) sum += a[i];
		}
		if (sum <= n) v1.push_back(sum), ans++;
	}
	for (int mask = 0; mask < (1 << (int) b.size()); ++mask) {
		int sum = 0;
		for (int i = 0; i < (int) b.size(); ++i) {
			if (mask & (1 << i)) sum += b[i];
		}
		if (sum <= n and sum != 0) v2.push_back(sum), ans++;
	}
	--ans;
	cerr << "-------------\n";
	for (auto u : v1) cerr << u << " ";
	cerr << "\n";
	for (auto u : v2) cerr << u << ' ';
	cerr << "\n";
	cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
