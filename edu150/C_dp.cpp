#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 5;

string s;
int n, hi, val[5];
LL dp[N][5][2];

LL rec(int curIdx, int mx, int used) {
	LL ans;
	if (!used) {
		for (int i = 0; i < 5; ++i) {
			LL curVal = val[s[curIdx] - 'A'];
			if (hi > s[curIdx] - 'A') curVal *= -1;
			ans = max(ans, curVal + rec(curIdx - 1, i, 1));
		}
	} else ans = max(ans, )
	hi = max(hi, s[curIdx] - 'A');
}
void solve() {
	cin >> s;
	n = (int) s.size();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
