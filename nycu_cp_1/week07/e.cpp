#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> prefixSum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            long long temp;
            cin >> temp;
            prefixSum[i+1] = prefixSum[i] + temp;
        }

        map<long long, long long> mp;
        long long ans = 0;
        for (const auto& num : prefixSum) {
            mp[num + 47]++;
            if (mp[num] > 0)
                ans += mp[num];
        }
        cout << ans << '\n';


    }
    return 0;
}