#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	bool free[n + 1]{};
	vector<tuple<int, int, int > > v;
	for (int i = 1; i <= n; ) {
		int st = i, end = i, mx = -1, mn = INT_MAX;
		while (i <= n and ara[i] > 0) {
			free[i] = 1;
			mx = max(mx, ara[i]);
			end = i;
			i++;
		}
		if (ara[st] != 0) v.push_back({st, end, mx});
		if (st == end) i++;
	}
	for (auto [i, j, l] : v) {
		if (i == j) {
			if (l == 2) {
				if (i - 1 >= 1 and !free[i - 1]) free[i - 1] = 1;
				if (i + 1 <= n and !free[i + 1]) free[i + 1] = 1;
			} else {
				if (i - 1 >= 1 and !free[i - 1]) free[i - 1] = 1;
				else if (i + 1 <= n and !free[i + 1]) free[i + 1] = 1;
			}
		} else {
			if (l == 2) {
				if (i - 1 >= 1 and !free[i - 1]) free[i - 1] = 1;
				if (j + 1 <= n and !free[j + 1]) free[j + 1] = 1;
			} else {
				if (i - 1 >= 1 and !free[i - 1]) free[i - 1] = 1;
				else if (j + 1 <= n and !free[j + 1]) free[j + 1] = 1;
			}
		}
	}
	int ans = (int) v.size();
	for (int i = 1; i <= n; ++i) {
		if (!free[i]) ans++;
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
