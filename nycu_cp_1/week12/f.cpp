#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int target; cin >> target;
		int n; cin >> n;
		vector<int> dp(10001, 100000);
		dp[0] = 0; // dp[X] = 要達到 X 所花的 coin 數量
		for (int i = 0; i < n; ++i) {
			int coin; cin >> coin;
			for (int j = 10000 - coin; j >= 0; --j) {
				if (dp[j] != 100000) {
					dp[j + coin] = min(dp[j + coin], dp[j] + 1);
				}
			}
		}
		int mn = 100000;
		int mn_idx = -1;
		for (int i = target; i < 10001; ++i) {
			if (dp[i] != 100000) {
				mn = dp[i];
				mn_idx = i;
				break;
			}
		}
		cout << mn_idx << ' ' << mn << '\n';
	}
	return 0;
}