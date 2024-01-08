#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	string s[2]; cin >> s[0] >> s[1];
	int t, q, sz = (int) s[0].size(); cin >> t >> q;
	multiset<int> unmatched, blockAndUnmatched, blkPos;
	vector<int> blockT[max(q, t) * 2 + 103];
	for (int i = 0; i < sz; i++) {
		if (s[0][i] != s[1][i]) unmatched.insert(i);
	}

	int time = 0;
	while (q--) {
		time++;
		for (auto u : blockT[time]) {
			if (blockAndUnmatched.find(u) != blockAndUnmatched.end()) blockAndUnmatched.erase(u);
			if (blkPos.find(u) != blkPos.end()) blkPos.erase(u);
		}
		int op; cin >> op;
		if (op == 1) {
			int pos; cin >> pos;
			--pos;
			blockT[time + t].push_back(pos);
			if (!blkPos.count(pos)) blkPos.insert(pos);
			if (unmatched.find(pos) != unmatched.end() and !blockAndUnmatched.count(pos)) blockAndUnmatched.insert(pos);
		} else if (op == 2) {
			int who1, pos1, who2, pos2; cin >> who1 >> pos1 >> who2 >> pos2;
			--who1, --pos1, --who2, --pos2;
			swap(s[who1][pos1], s[who2][pos2]);
			if (s[0][pos1] != s[1][pos1]) {
				if (!unmatched.count(pos1)) {
					unmatched.insert(pos1);
					if (blkPos.count(pos1)) blockAndUnmatched.insert(pos1);
				}
			} else {
				if (unmatched.count(pos1)) {
					unmatched.erase(pos1);
					if (blockAndUnmatched.count(pos1)) blockAndUnmatched.erase(pos1);
				}
			}
			if (s[0][pos2] != s[1][pos2]) {
			    if (!unmatched.count(pos2)) {
			    	unmatched.insert(pos2);
			    	if (blkPos.count(pos2)) blockAndUnmatched.insert(pos2);
			    }
			} else {
				if (unmatched.count(pos2)) {
					unmatched.erase(pos2);
					if (blockAndUnmatched.count(pos2)) blockAndUnmatched.erase(pos2);
				}
			}
		} else {
			if ((int) blockAndUnmatched.size() == (int) unmatched.size()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
