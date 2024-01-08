#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int a = (int) 1e9;
	vector<int> v;
	for (int i = 1; i <= n; ++i) v.push_back(a--);
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
