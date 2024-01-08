#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
  LL n, k, x; cin >> n >> k >> x;
  LL L = k * (k + 1) / 2, R = (n * (n + 1) / 2) - ((n - k) * (n - k + 1) / 2);
  if (x >= L and x <= R) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
