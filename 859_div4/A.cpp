#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int a, b, c; cin >> a >> b >> c;
	if (a - b == c) cout << "-\n";
	else cout << "+\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
