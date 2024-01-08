#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	char ara[n + 1][n + 1], a[n + 1][n + 1];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) cin >> ara[i][j], a[i][j] = ara[i][j];
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = temp;
        }
    }
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < n; ++j) {cerr << a[i][j] << " ";}
 		cerr << '\n';

 	}
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
    	for (int j = 0; j < n; ++j) {
    		ans += abs(ara[i][j] - a[i][j]);
    	}
    }
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
