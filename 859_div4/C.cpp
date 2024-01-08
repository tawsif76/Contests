#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1' || s[i] == '0') continue;
		char put = '0';
		if (i - 1 >= 0 and s[i - 1] == '0') put = '1';
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == s[i]) s[j] = put;
		}
		s[i] = put;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
