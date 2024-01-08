#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int)1e5 + 7;

int n;
int ara[N], tree[4 * N];

struct ST {
  int tree[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(tree, 0, sizeof tree);
  }
  void build(int node, int b, int e) {
    if (b == e) {
      tree[node] = ara[b];
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = (tree[l] & tree[r]); // change this
  }
  int query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return ((1 << 30) - 1); // return appropriate value
    if (b >= i && e <= j) return tree[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return (query(l, b, mid, i, j) & query(r, mid + 1, e, i, j)); // change this
  }
}t;


void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	build(1, 1, n);
	int q; cin >> q;

	auto ok = [&] (int l, int k, int idx) {
		if (idx > n) return false;
		int AND = query(1, 1, n, l, idx);
		return AND >= k;
	};

	while (q--) {
		int l, k; cin >> l >> k;
		int lo = l, hi = n + 1;
		while (lo < hi) {
			int mid = (lo + hi + 1) >> 1;
			if (ok(l, k, mid)) lo = mid;
			else hi = mid - 1;
		}
		if (query(1, 1, n, l, lo) < k) cout << "-1 ";
		else cout << lo << " ";
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
