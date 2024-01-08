#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, k, g; cin >> n >> k >> g;
	LL saved = min((n - 1) * ((g - 1) / 2), k * g);
	LL left = k * g - saved;
	if (left % g >= (g + 1) / 2) saved += (left % g) - g;
	else saved += left % g;
	cout << max(0LL , saved) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
		