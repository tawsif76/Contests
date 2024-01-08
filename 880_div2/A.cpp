#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1], cnt[103]{};
	for (int i = 1; i <= n; i++) cin >> ara[i], cnt[ara[i]]++;
	sort(ara + 1, ara + n + 1);
	for (int i = 1; i <= n - 1; ++i) {
		if (ara[i + 1] - ara[i] > 1) {
			cout << "NO\n";
			return;
		}
	}
	if (ara[1] != 0) {
		cout << "NO\n";
		return;
	}
	vector<int> v;
	for (int i = 0; i <= 100; ++i) {
		if (cnt[i]) {
			v.push_back(cnt[i]);
		}
	}
	for (int i = 0; i < (int) v.size() - 1; ++i) {
		if (v[i] < v[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
