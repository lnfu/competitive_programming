#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C, n;
	while (cin >> C >> n) {
		vector<int> weight(n);
		vector<int> value(n);

		for (int i = 0; i < n; ++i) {
			cin >> value[i] >> weight[i];
		}

		// dp
		vector<vector<int>>      dp(n + 1, vector<int>(C + 1, 0)); // value
		vector<vector<bool>> record(n    , vector<bool>(C + 1, false)); // 要 or 不要
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= C; j++) {
				if (j - weight[i] < 0) {
					dp[i+1][j] = dp[i][j]; // 不放
				}
				else {
					if (dp[i][j-weight[i]] + value[i] > dp[i][j]) {
						// 放
						dp[i+1][j] = dp[i][j-weight[i]] + value[i];
						record[i][j] = true;
					} else {
						// 不放
						dp[i+1][j] = dp[i][j];
					}
				}
			}
		}

		int t = 0;
		stack<int> stk;
		for (int i = n - 1, j = C; i >= 0; --i) {
			if (record[i][j]) {
				// 放
				t++;
				stk.push(i);
				j -= weight[i];
			}
		}
		cout << t << '\n';
		while (!stk.empty()) {
			cout << stk.top() << ' ';
			stk.pop();
		}
		cout << '\n';
	}
	return 0;
}