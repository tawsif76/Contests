#include <bits/stdc++.h>

using namespace std;
using LL = unsigned long long;

void solve() {
	int n; cin >> n;
	LL c; cin >> c;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	LL lo = 0, hi = (LL) 1e9 + 1;
	while (lo < hi) {
		LL mid = (lo + hi) >> 1LL;
		LL cur = 0;
		bool big = 0;
		for (int i = 1; i <= n; ++i) {
			LL val = ((ara[i] + (2 * mid)) * (ara[i] + (2 * mid)));
			if (val > c or (cur + val) > c) {
				big = 1;
				break;
			}
			cur += val;
		}
		if (cur == c and !big) {
			cout << mid << "\n";
			return;
		} else if (cur > c or big) {
			hi = mid;
		} else lo = mid + 1;
	}
}	

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
