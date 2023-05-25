#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

void printLIS(int i, vector<int>& seq
	               , vector<int>& length
	               , vector<int>& prev) {
	if (prev[i] != -1)
		printLIS(prev[i], seq, length, prev);
	cout << ' ' << seq[i];
}

void LIS(int n, vector<int>& seq) {
	vector<int> length(n, 1); // 從 i 開始的 LIS 長度
	vector<int> prev(n, -1);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (seq[i] < seq[j]) {
				if (length[i] + 1 > length[j] || 
				   (length[i] + 1 == length[j] && seq[i] < seq[prev[j]])) {
					length[j] = length[i] + 1;
					prev[j] = i;
				}
			}
		}
	}


	int mx = 0;
	int mx_idx = -1;
	for (int i = 0; i < n; i++) {
		if (length[i] > mx
			|| (length[i] == mx && seq[i] < seq[mx_idx])) {
			mx = length[i];
			mx_idx = i;
		}
	}
	cout << mx;
	printLIS(mx_idx, seq, length, prev);
	cout << '\n';
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n = nxt();
		if (n == 0)
			return 0;

		vector<int> seq(n);
		generate(all(seq), nxt);

		LIS(n, seq);
	}

	return 0;
}