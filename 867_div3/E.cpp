#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, ans = 0; cin >> n;
	string s; cin >> s;
	if (n & 1) {
		cout << "-1\n";
		return;
	}
	int fre[26]{};
	for (auto u : s) fre[u - 'a']++;
	for (int i = 0; i < 26; ++i) {
		if (fre[i] >= n / 2 + 1) {
			cout << "-1\n";
			return;
		}
	}
	memset(fre, 0, sizeof fre);
	multiset<int> ms;
	for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - 1 - i]) {
				fre[s[i] - 'a']++;
			}
	}
	for (int i = 0; i < 26; ++i) {
		if (fre[i]) ms.insert(fre[i]);
	}
	while ((int) ms.size() > 1) {
		auto x = prev(ms.end());
		auto y = ms.begin();
		if ((*x) - 1 > 0) ms.insert((*x) - 1);
		if ((*y) - 1 > 0) ms.insert((*y) - 1);
		ms.erase(x);
		ms.erase(y);
		ans++;
	} 
	if (!ms.empty()) ans += *ms.begin();
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
