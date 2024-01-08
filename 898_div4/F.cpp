#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int m;

void solve() {
	m++;
	int n, limit; cin >> n >> limit;
	int a[n + 1], h[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> h[i];
	vector<pair<int, int > > ranges;
	int l = 1;
	for (int i = 2; i <= n; ++i) {
		if (h[i - 1] % h[i]) {
			ranges.push_back({l, i - 1});
			l = i;
		}
	}
	if (ranges.empty() or ranges.back().second != n) ranges.push_back({l, n});
	int ans = 0;
	for (auto [x, y] : ranges) {
		int L = x, R = x, sum = 0;
		while (L <= R and L <= y and R <= y) {
			while (L <= y and R <= y and L == R and sum + a[R] > limit) L++, R++;
			if (R <= y and L <= y and sum + a[R] > limit) sum -= a[L], L++;
			else if (R <= y and L <= y) sum += a[R], ans = max(ans, R - L + 1), R++;
		}
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    m = 0;
    cin >> t;
    while(t--) solve();
}
