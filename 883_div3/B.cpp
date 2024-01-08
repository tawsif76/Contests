#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	char ara[4][4];
	for (int i = 1; i <= 3; ++i) 
		for (int j = 1; j <= 3; ++j) cin >> ara[i][j];
	for (int i = 1; i <= 3; ++i) {
		if (ara[i][1] == ara[i][3] and ara[i][1] == ara[i][2] and ara[i][2] == ara[i][3] and ara[i][1] != '.') {
			cout << ara[i][1] << "\n";
			return;
		}
	}
	for (int i = 1; i <= 3; ++i) {
		if (ara[1][i] == ara[3][i] and ara[1][i] == ara[2][i] and ara[2][i] == ara[3][i] and ara[1][i] != '.') {
			cout << ara[1][i] << "\n";
			return;
		}
	}
	if (ara[1][1] == ara[3][3] and ara[1][1] == ara[2][2] and ara[3][3] and ara[3][3] != '.') {
		cout << ara[1][1] << "\n";
		return;
	}
	if (ara[1][3] == ara[3][1] and ara[1][3] == ara[2][2] and ara[3][1] and ara[3][1] != '.') {
		cout << ara[1][3] << "\n";
		return;
	}
	cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
