#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];

	sort(ara + 1, ara + n + 1);

	int lo = 0, hi = ara[n];

	auto test = [&] (int dif) {
		int x = ara[1] + dif, cnt = 1;
		for (int i = 2; i <= n; ++i) {
			if (abs(ara[i] - x) > dif) {
				if (cnt >= 3) return false;
				x = ara[i] + dif;
				cnt++;
			}
		}
		return true;
	};
	while (lo < hi) {
		int mid = lo + hi >> 1;
		if (test(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
