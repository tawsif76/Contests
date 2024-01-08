#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int a[n + 1], b[n + 1], mxN = -1, mxP = -1, idxN = -1, idxP = -1, cntN = 0, cntP = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
		cntN += a[i] < 0;
		cntP += a[i] >= 0;
		if (a[i] < 0 and abs(a[i]) > mxN) mxN = abs(a[i]), idxN = i;
		if (a[i] >= 0 and a[i] > mxP) mxP = a[i], idxP = i;
	}	

	vector<pair<int, int> > v;

	auto chk = [&] (int a[]) {
		bool ok = 1;
		for (int i = 2; i <= n; ++i) ok &= a[i] >= a[i - 1];
		return ok;
	};

	auto allNeg = [&] () {
		v.clear();
		while (cntN and cntP and abs(a[idxN]) < a[idxP]) a[idxN] *= 2, v.push_back({idxN, idxN});
		for (int i = 1; i <= n; ++i) {
			if (a[i] > 0) a[i] += a[idxN], v.push_back({i, idxN});
		}
		for (int i = n - 1; i >= 1; --i) {
			if (a[i] > a[i + 1]) a[i] += a[i + 1], v.push_back({i, i + 1});
		}
		return chk(a) and (int) v.size() <= 31;
	};

	auto allPos = [&] () {
		v.clear();
		while (cntN and cntP and mxP != 0 and b[idxP] < abs(b[idxN])) b[idxP] *= 2, v.push_back({idxP, idxP});
		for (int i = 1; i <= n; ++i) {
			if (b[i] < 0) b[i] += b[idxP], v.push_back({i, idxP});
		}
		for (int i = 2; i <= n; ++i) {
			if (b[i] < b[i - 1]) b[i] += b[i - 1], v.push_back({i, i - 1});
		}
		return chk(b) and (int) v.size() <= 31;
	};

	if (idxN != -1 and allNeg()) {
		cout << (int) v.size() << '\n';
		for (auto [x, y] : v) cout << x << " " << y << "\n";
	} else if (allPos()) {
		cout << (int) v.size() << "\n";
		for (auto [x, y] : v) cout << x << " " << y << "\n";
	} 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 	cin >> t;
    while(t--) solve();
}
