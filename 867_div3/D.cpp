#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	if (n == 1) cout << "1\n";
	else {
		if (n & 1)  cout << "-1\n";
		else {
			vector<int> v(n);
			v[0] = n, v[1] = n - 1, v[n - 1] = 1;
			bool par = 1;
			for (int i = 2, j = n - 1; i <= n / 2; i++, --j) {
				v[i] = v[j];
				if (par) v[i]++;
				else v[i]--;
				par ^= 1;
				v[j - 1] = v[0] - v[i];
			}
			for (auto u : v) cout << u << " ";
			cout << "\n";
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
