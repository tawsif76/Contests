#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<LL> pos, neg;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (x < 0) neg.push_back(x);
		else pos.push_back(x);
	}
	if (n == 1 or neg.empty()) {
		cout << "No\n";
		return;
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());
	LL dif = pos[0] - neg[0], ok = 1; 
	for (int u : pos) ok &= (u < dif);
	for (int u : neg) ok &= (abs(u) < dif);
	if (!ok) cout << "No\n";
	else {
		cout << "Yes\n";
		LL sum = 0;
		int i = 0, j = 0;
		while (i < (int) pos.size() or j < (int) neg.size()) {
			if (i < (int) pos.size() and (sum + pos[i] < dif)) sum += pos[i], cout << pos[i++] << " ";
			else if (j < (int) neg.size()) sum += neg[j], cout << neg[j++] << " ";
			else if (i < (int) pos.size()) sum += pos[i], cout << pos[i++] << " ";
		} 
		cout << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
