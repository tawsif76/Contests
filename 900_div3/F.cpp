#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e6 + 1;
bool is_com[N];
vector<int> prime;
int spf[N];

void sieve() {
	spf[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!is_com[i]) {
			spf[i] = i;
			prime.push_back(i); 
		}
		for (int j = 0; j < (int) prime.size() and 1LL * prime[j] * i < N; ++j) {
			is_com[prime[j] * i] = true;
			spf[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break; 
		}
	}
}

void solve() {
	int _n, q; cin >> _n >> q;
	map<int, int> rt;

	auto factorRt = [&] (int val) {
		if (val == 1) return;
		while (spf[val] != 1) rt[spf[val]]++, val /= spf[val];
	};

	factorRt(_n);
	while (q--) {
		int typ; cin >> typ;
		if (typ == 1) {
			int x; cin >> x;
			factorRt(x);
			bool ok = 1;
			map<int, int> here;
			for (auto [A, B] : rt) {
				int H = B + 1;
				while (spf[H] != 1) here[spf[H]]++, H /= spf[H];
			}
			for (auto [A, B] : here) ok &= (B <= rt[A]);
			cout << (ok ? "YES\n" : "NO\n");
		} else {
			rt.clear();
			factorRt(_n);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t = 1; cin >> t; 
    while (t--) solve();
}
