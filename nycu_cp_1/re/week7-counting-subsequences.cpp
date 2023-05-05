#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int psum = 0;
        int ans = 0;
        map<int, int> ma;
        for (int i = 0; i < N; i++) {
            int input; cin >> input;

            ma[psum]++;

            psum += input;
            ans += ma[psum - 47];
            //    1, 2, 23, 24
            // 0, 1, 3, 26, 50
        }
        cout << ans << '\n';
    }

    return 0;
}