#include <bits/stdc++.h>

using namespace std;

bool isSquare(int num) {
	for (int i = 1; i < num; ++i) {
		if (i*i == num)
			return true;
	}
	return false;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<vector<int>> peg(N);

		int empty = 0;
		for (int i = 1; i < 1e9; ++i) {
			bool placed = false;
			for (int j = 0; j < N; ++j) {
				if (peg[j].size() == 0)
					continue;
				if (isSquare(peg[j][peg[j].size() - 1] + i)) {
					peg[j].push_back(i);
					placed = true;
					break;
				}
			}

			if (!placed && empty < N) {
				peg[empty].push_back(i);
				empty++;
				placed = true;
			}

			if (!placed) {
				cout << i - 1 << '\n';
				break;
			}
		}
	}
	return 0;
}