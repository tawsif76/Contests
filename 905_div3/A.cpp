#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int pos[11];
	for (int i = 1; i <= 9; ++i) pos[i] = i;
	pos[0] = 10;
	string s; cin >> s;
	int ans = abs(1 - pos[s[0] - '0']) + 1;
	for (int i = 1; i < 4; ++i) ans += abs(pos[s[i] - '0'] - pos[s[i - 1] - '0']) + 1;
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
