#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int a = 0, b = 0, c = 0;
	char ara[4][4];
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j) cin >> ara[i][j];
	for (int i = 1; i <= 3; ++i) {
		set<char> s;
		for (int j = 1; j <= 3; ++j) {
			if (ara[i][j] != '?') s.insert(ara[i][j]);
		}
		if ((int) s.size() != 3) {
			for (auto l : s) {
				if (l == 'A') a = 1;
				else if (l == 'B') b = 1;
				else if (l == 'C') c = 1;
			}
			break;
		}
	}
	if (!a) cout << "A\n";
	else if (!b) cout << "B\n";
	else cout << "C\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
