#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> v(m);
	vector<int> w(m);
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; ++i) {
		cin >> v[i];
		cin >> w[i];
	}

	// not useful
	for (int j = 0; j <= n; ++j) {
		dp[0][j] = 0; // 只有 0 個選擇時 = 0
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j - v[i] >= 0) {
				dp[i+1][j] = max(dp[i][j], dp[i][j-v[i]] + v[i] * w[i]);
			}
			else {
				dp[i+1][j] = dp[i][j];
			}
		}
	}
	cout << dp[m][n] << '\n';
	return 0;
}



// m = 0      0,  0,  0,  ...,  0,  0,  0, ...
// m = 1      0,  0,  0,  ...,  vi*wi, vi*wi, ...
// m = 2      0

