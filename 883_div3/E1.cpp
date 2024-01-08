#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e6 + 5;

bool has[N];

void solve() {
    int n; cin >> n;
    if (has[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (LL k = 2; k <= 1000; ++k) {
        LL cur = k * k;
        for (LL x = 3; x <= 20; ++x) {
            cur *= k;
            LL val = (cur - 1) / (k - 1);
            if (val >= (LL) 1e6) break;
            if (val == 13) cerr << k << " " << x << endl;
            if ((cur - 1) % (k - 1) == 0) has[val] = 1;
        }
    } 
    cin >> t;
    while(t--) solve();
}