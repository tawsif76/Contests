#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, k; cin >> n >> k;
	if (k > 33) {
		cout << "0\n";
		return;
	}
	int ans = 0;
	for (int i = n; i >= 0; --i) {
		int last = n, secondLast = i, ok = 1;
		vector<int> v = {last, secondLast};
		int nk = k - 2;
		while (nk > 0) {
			int now = last - secondLast;
			if (now < 0) {
				ok = 0;
				break;
			}
			v.push_back(now);
			last = secondLast;
			secondLast = now;
			--nk;
		}
		reverse(v.begin(), v.end());
		if (ok) {
			bool nok = 1;
			for (int i = 1; i < (int) v.size(); ++i) nok &= (v[i] >= v[i - 1]);
			if (nok) ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
