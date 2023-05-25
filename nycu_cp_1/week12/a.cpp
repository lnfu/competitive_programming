#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;


int nxt() {
	int x;
	cin >> x;
	return x;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N = nxt(), M = nxt(), K = nxt();
	vector<int> plot(N), circular(M), square(K);
	generate(all(plot), nxt);
	generate(all(circular), nxt);
	generate(all(square), nxt);
	sort(all(plot), greater<int>());
	sort(all(circular), greater<int>());
	sort(all(square), greater<int>());

	int pi = 0, ci = 0, si = 0;
	int cnt = 0;
	while (pi < N) {
		if (ci >= M && si >= K)
			break;
		if (ci < M && 2 * circular[ci] * circular[ci] > square[si] * square[si]) {
			if (circular[ci] < plot[pi]) {
				pi++;
				cnt++;
			}
			ci++;
		} else {
			if (square[si] * square[si] < 2 * plot[pi] * plot[pi]) {
				pi++;
				cnt++;
			}
			si++;
		}
	}
	cout << cnt << '\n';


	return 0;
}