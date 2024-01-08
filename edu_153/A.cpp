#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	if (n == 2 and s == "()") {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	bool f = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == ')' and s[i + 1] == '(')  f = 1;
	}
	if (f) {
		for (int i = 0; i < n; ++i) cout << "(";
		for (int i = 0; i < n; ++i) cout << ")";
	} else {
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') cout << s[i] << ")";
			else cout << "(" << s[i];
		}
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
