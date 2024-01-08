#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int a[n + 1], b[n + 1], mxa = -1, mxb = -1;
	for (int i = 1; i <= n; ++i) cin >> a[i], mxa = max(a[i], mxa);
	for (int i = 1; i <= n; ++i) cin >> b[i], mxb = max(b[i], mxb);
	if (a[n] != mxa) {
		mxa = -1, mxb = -1;
		for (int i = 1; i <= n - 1; ++i) if (a[i] > a[n]) swap(a[i], b[i]);
		for (int i = 1; i <= n; ++i) mxb = max(b[i], mxb);
		for (int i = 1; i <= n; ++i) mxa = max(a[i], mxa);
		if (mxb == b[n] and a[n] == mxa) cout << "Yes\n";
		else cout << "No\n";
	} else if (b[n] != mxb) {
		mxa = -1, mxb = -1;
		for (int i = 1; i <= n - 1; ++i) if (b[i] > b[n]) swap(a[i], b[i]);
		for (int i = 1; i <= n; ++i) mxa = max(a[i], mxa);
		for (int i = 1; i <= n; ++i) mxb = max(b[i], mxb);
		if (mxa == a[n] and mxb == b[n]) cout << "Yes\n";
		else cout << "No\n";		
	} else cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
