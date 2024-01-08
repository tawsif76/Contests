#include <bits/stdc++.h>

using namespace std;
using LL = unsigned long long;

const LL inf = (LL) 1e18;

void solve() {
    LL n; cin >> n;

    auto ok = [&] (LL x, LL mid) {
        LL sum = 0, pow = 1, cnt = 0;
        while (cnt < x) {
            cnt++;
            sum += pow;
            if (n / pow < mid) break;
            pow *= mid;
        }
        if (cnt != x) return 3;
        if (sum == n) return 1;
        else if (sum < n) return 2;
        else return 3;
    };
    for (LL x = 3; x <= 60; ++x) {
        LL lo = 2, hi = (LL) 1e9 + 1;
        int cnt = 0;
        while (lo < hi) {
            LL mid = (lo + hi) >> 1LL;//k
            int d = ok(x, mid);
            if (d == 1) {
                cout << "YES\n";
                return;
            } else if (d == 2) lo = mid + 1;
            else hi = mid;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}