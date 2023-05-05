#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & (-x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N + 1, 0);
    while (Q--) {
        char op;
        cin >> op;
        if (op == '+') {
            // update
            int pos, val;
            cin >> pos >> val;
            pos += 1; // 1 ~ N

            while (pos <= N) {
                arr[pos] += val;
                pos += lowbit(pos);
            }
        } else {
            // query
            int pos;
            cin >> pos;
            long long ans = 0;

            while (pos > 0) {
                ans += arr[pos];
                pos -= lowbit(pos);
            }

            cout << ans << '\n';
        }
    }
    return 0;
}