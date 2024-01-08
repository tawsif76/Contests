#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int b, c, h; cin >> b >> c >> h;
	if (b > (c + h)) cout << 2 * (c + h) + 1 << "\n";
	else {
		cout << b + b - 1 << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
