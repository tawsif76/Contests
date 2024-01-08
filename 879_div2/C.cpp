#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	string x, y; cin >> x >> y;
	int comp = 0, mark[n + 1]{}, must = 0;
	for (int i = 0, j = n - 1; i < n and i < j; i++, --j) {
		if (x[i] == y[j] and x[j] == y[i]) comp++, mark[i] = mark[j] = 1;
	}
	bool p = 0;
	for (int i = 0, j = n - 1; i < n and i < j; i++, --j) {
		if (mark[i]) continue;
		p = 1;
		map<char, int> cnt;
		cnt[x[i]]++, cnt[x[j]]++, cnt[y[i]]++, cnt[y[j]]++;
		int mx = -1;
		cerr << i << " " << j << "\n";
		for (auto u : cnt) {
			//cerr << u.first << " " << u.second << '\n';
			mx = max(mx, u.second);
		}
		//cerr << i << " " << j << " " << mx << endl;;
		must += (2 * (4 - mx));	
	}
	int add = 0;
	if ((n & 1) and x[n / 2] != y[n / 2]) add = 1;
	cerr << must << endl;
	if (!comp) cout << must - 1 + add << "\n";
	else if (!p) cout << 2 << "\n";
	else {
		auto chk = [&] (int hi) {
			bool flip = 0;
			for (int i = 1; i <= hi; ++i) {
				if (i % 2 == 0) flip ^= 1;
			}
			if (!flip) hi += 2;
			return hi;
		};
		cout << min(chk(must), chk(must - 1)) << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
