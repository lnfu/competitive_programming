#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& v, vector<int>& dep, vector<vector<int>>& an, int x, int d) {
	dep[x] = d;
	for (auto u : v[x]) {
		if (dep[u] == -1) {
			an[u][0] = x;
			dfs(v, dep, an, u, d + 1);
		}
	}
}

int lca(vector<vector<int>>& an, vector<int>& dep, int x, int y) {
	if (x == y)
		return x;

	if (dep[x] > dep[y])
		swap(x, y);

	// dep[x] < dep[y] -> y 上移

	int diff = dep[y] - dep[x];
	for (int i = 0; diff > 0 && i <= 20; ++i) {
		if (diff & 1)
			y = an[y][i];
		diff >>= 1;
	}

	// x and y are in same depth
	if (x == y)
		return x;

	// 兩個一起往上
	for (int i = 20; i >= 0; --i) {
		if (an[x][i] != an[y][i]) {
			x = an[x][i];
			y = an[y][i];
		}
	}

	return an[x][0];
}

int main() {
	int n; cin >> n;
	vector<vector<int>> v(n+1, vector<int>()); // 0 is not used
	vector<int> dep(n+1, -1);
	for (int idx = 1; idx < n; ++idx) {
		int i, j; cin >> i >> j;
		v[i].push_back(j);
		v[j].push_back(i);
	}

	vector<vector<int>> an(n+1, vector<int>(21, 0)); // 祖先，2^20 > 20000

	dfs(v, dep, an, 1, 0);

	dep[0] = 0; // trivial

	for (int j = 1; j <= 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			an[i][j] = an[an[i][j-1]][j-1];
		}
	}


	int total = 0;
	for (int i = 1; i <= n / 2; ++i) {
		for (int j = 2; i*j <= n; ++j) {
			total += (dep[i] + dep[i*j] - 2*dep[lca(an, dep, i, i*j)] + 1);
		}
	}
	cout << total << endl;


	return 0;
}