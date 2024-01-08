#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, occ = 0; cin >> n;
	LL ara[n + 1];
	set<LL> s; 
	for (int i = 1; i < n; ++i) cin >> ara[i];
	bool ok = 1;
	LL suspicious = 0, tot = (n + 1) * (n + 2) / 2;
	for (int i = 2; i < n; ++i) {
		LL dif = ara[i] - ara[i - 1];
		if (s.count(dif) or dif > n) suspicious = dif, occ++;
		s.insert(dif);
	}
	if (ara[1] > n) suspicious = ara[1], occ++;
	else {
		if (s.count(ara[1])) occ++, suspicious = ara[1];
		else s.insert(ara[1]);
	}
	if (occ == 0) cout << "YES\n";
	else if (occ > 1) cout << "NO\n";
	else {
		vector<int> cand;
		for (int i = 1; i <= n; ++i) {
			if (!s.count(i)) cand.push_back(i);
		}
		if ((int) cand.size() != 2) cout << "NO\n";
		else {
			if (cand[0] + cand[1] == suspicious) cout << "YES\n";
			else cout << "NO\n";
		}
	}
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
