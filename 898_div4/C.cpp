#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	char ara[11][11];
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j) cin >> ara[i][j];
	int p = 0;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			if (ara[i][j] == 'X') {
				if (i == 1 or i == 10 or j == 1 or j == 10) p += 1;
				else if (i == 2 or i == 9 or j == 2 or j == 9) p += 2;
				else if (i == 3 or i == 8 or j == 3 or j == 8) p += 3;
				else if (i == 4 or i == 7 or j == 4 or j == 7) p += 4;
				else p += 5;
			}
		}
	}
	cout << p << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
