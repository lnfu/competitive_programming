#include <bits/stdc++.h>

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

int main() {
	int k = nxt();
	string ans;

	if (k <= 25) {
		ans.push_back('a');
		ans.push_back('a' + k);
	}
	// else if (k <= 50) {
	// 	ans.push_back('a');
	// 	ans.push_back('z');
	// 	ans.push_back('z' - k);
	// }
	else {
		ans.push_back('a');
		int cnt = 0;
		while (k > 25) {
			if (cnt % 2) {
				ans.push_back('a');
			}
			else {
				ans.push_back('z');
			}

			cnt = (cnt + 1) % 2;
			k -= 25;
		}


		if (cnt % 2) {

			ans.push_back('z' - k);
			int n = ans.size();
			int l = 1;
			int r = n - 1;
			while (r > l) {
				while (ans[l] > 'b' && ans[r] > 'b') {
					ans[l] -= 1;
					ans[r] -= 2;
				}
				if (ans[l] <= 'b')
					l += 2;
				else
					r -= 2;
			}
		}
		else {

			ans.push_back('a' + k);
			int n = ans.size();
			int l = 1;
			int r = n - 1;
			while (r > l) {
				while (ans[l] > 'b' && ans[r] < 'y') {
					ans[l] -= 1;
					ans[r] += 2;
				}
				if (ans[l] <= 'b')
					l += 2;
				else
					r -= 2;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}