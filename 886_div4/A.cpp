#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	if (v[2] + v[1] >= 10) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
