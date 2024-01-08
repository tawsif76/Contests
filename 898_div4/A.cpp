#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			swap(s[i], s[j]);
			if (s == "abc") {
				cout << "YES\n";
				return;
			}
			swap(s[i], s[j]);
		}
	}
	if (s == "abc") cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
