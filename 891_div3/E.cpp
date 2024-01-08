#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<int> v(n + 1), a(n + 1);
	map<int, LL> less, gt, idx, ans;
	for (int i = 1; i <= n; ++i) cin >> v[i], a[i] = v[i];
	sort(v.begin(), v.end());
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		less[v[i]] = i;
		gt[v[i]] = max(gt[v[i]], 1ll* (n - i + 1));
		if (i + 1 <= n) {
			int dif = v[i + 1] - v[i] - 1;
			if (dif >= 1) {
				less[v[i] + 1] = 1LL * dif * i; 
				gt[v[i] + 1] = max(gt[v[i] + 1], 1LL * dif * (n - i));
			}
		}
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<LL> pL, pG;
	pL.push_back(0LL), pG.push_back(0LL);
	for (int i = 1; i < (int) v.size(); ++i) {
		pL.push_back(pL.back() + (1LL * less[v[i]]));
		pG.push_back(pG.back() + (1ll * gt[v[i]]));
		idx[v[i]] = cnt++;
		if (i + 1 < (int) v.size() and v[i + 1] - v[i] > 1) {
			pL.push_back(pL.back() + (1ll * less[v[i] + 1]));
			pG.push_back(pG.back() + (1LL * gt[v[i] + 1]));
			idx[v[i] + 1] = cnt++;
		}
	}
	for (int i = 1; i < (int) v.size(); ++i) {
		ans[v[i]] = pL[idx[v[i]] - 1] + pG.back() - pG[idx[v[i]]] + n;
	}
	for (int i = 1; i <= n; ++i) cout << ans[a[i]] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
