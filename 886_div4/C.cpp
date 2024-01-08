#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	char ara[9][9];
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cin >> ara[i][j];
			if (ara[i][j] != '.') cout << ara[i][j];
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
