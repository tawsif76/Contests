#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	string cur = "";
	for (int i = 0; i < n; ++i) {
		if ((int) cur.size() == 3) {
			cout << cur;
			if (i != n - 1) cout << ".";
			cur.clear();
		}
		if (s[i] == 'a' or s[i] == 'e') {
			cur += s[i];

		} else {
			if ((int) cur.size() == 2) {
				if (s[i + 1] == 'a' or s[i + 1] == 'e') {
					cout << cur;
					if (i != n - 1) cout << ".";
					cur.clear();
					cur += s[i];
				} else cur += s[i];
			} else cur += s[i];
		}
	}
	if (!cur.empty()) cout << cur << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
