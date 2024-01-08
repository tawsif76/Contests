#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL func(int a, int b) {
    if (a == 0) return 0LL;
    if (b == 0) return 1LL;
    if (a >= 2 * b) return func(a % (2 * b), b) + ((a / (2 * b)) * 3LL);
    if (b >= 2 * a) return func(a, b % (2 * a)) + ((b / (2 * a)) * 3LL);
    return 1 + func(b, abs(a - b));
}

void solve() {
    int n;  cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        if (a[i] or b[i]) {   
            LL need = func(a[i], b[i]);
            s.insert(need % 3);
        }
    }
    if ((int) s.size() <= 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
