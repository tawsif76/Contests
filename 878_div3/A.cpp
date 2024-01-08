#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; ) {
		int j = i + 1;
		while (j < n and s[i] != s[j]) j++;
		cout << s[i];
		i = j + 1;
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
