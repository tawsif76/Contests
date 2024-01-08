#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s; cin >> s;
	int n = (int) s.size();
	int cnt[7]{}, val[7];
	LL pre[n + 1]{}; 
	vector<int> same[7], last[7];
	for (int i = 0, u = 1; i < 5; ++i, u *= 10) val[i] = u;

	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < n; ++k) {
			if (s[k] - 'A' > i) last[i].push_back(k);
		}
	}
	auto biggerIdx = [&] (int op) {
		if (last[op].empty()) return -1;
		else return *prev(last[op].end());
	};

	for (int i = 0; i < n; i++) {
		int idx = biggerIdx(s[i] - 'A');
		LL v = val[s[i] - 'A'];
		if (i < idx) v *= -1;
		if (i - 1 >= 0) pre[i] = pre[i - 1] + v;
		else pre[i] = v;
	}
	LL ans = LLONG_MIN;
	for (int i = 0; i < n; ++i) {
		for (int put = 0; put < 5; ++put) {
			LL curAns = 0;
			for (int op = 0; op < 5; ++op) {
				int del = -1;
				if (put > op) curAns += (-1LL * cnt[op] * val[op]);
				else {
					int idx = biggerIdx(op);
					//if (i == 26 and put == 3) cerr << op << " " << idx << endl;
					if (idx > i) curAns += (-1LL * cnt[op] * val[op]);
					else if (idx <= i and !same[op].empty()) {
						if (i == idx) last[op].pop_back(), del = idx;
						if (last[op].empty()) curAns += (cnt[op] * val[op]);
						else {
							idx = biggerIdx(op);
							int lb = lower_bound(same[op].begin(), same[op].end(), idx) - same[op].begin();
							curAns += (-1LL * lb * val[op]);
							curAns += (((int) same[op].size() - lb) * val[op]);
						}
						if (del != -1) last[op].push_back(del);
					} else curAns += (cnt[op] * val[op]);
				}
			}
			if (biggerIdx(put) > i) curAns += (-1LL * val[put]);
			else curAns += val[put];
			ans = max(ans, curAns + pre[n - 1] - pre[i]);
		}
		cnt[s[i] - 'A']++;
		same[s[i] - 'A'].push_back(i);
	}

	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
