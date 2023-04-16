// dilbert's hotel

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    map<int, int> diff;
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        diff[B] += A;
        diff[B+C] -= A;
    }

    int accu = 0;
    int ans = INT_MIN;
    for (const auto& [key, value] : diff) {
        // cout << key << ' ' << value << '\n';
        accu += value;
        if (accu > ans)
            ans = accu;
    }
    cout << ans << endl;
    return 0;
}