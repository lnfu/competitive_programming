// 3 nearest neighbors

#include <bits/stdc++.h>

using namespace std;

long long dis(long long a, long long b) {
    return ((a > b) ? (a - b) : (b - a));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<pair<long long, int>> data;
    for (int i = 0; i < N; i++) {
        long long F;
        int C;
        cin >> F >> C;
        data.push_back({F, C});
    }

    for (int i = 0; i < Q; i++) {
        long long F;
        cin >> F;
        vector<pair<long long, int>> diff;
        for (const auto& d : data)
            diff.push_back({dis(F, d.first), d.second});
        
        int ans = 0;
        auto it = min_element(diff.begin(), diff.end());
        ans += (*it).second;
        (*it).first = LLONG_MAX;

        it = min_element(diff.begin(), diff.end());
        ans += (*it).second;
        (*it).first = LLONG_MAX;

        it = min_element(diff.begin(), diff.end());
        long long temp = (*it).first;
        ans += (*it).second;
        (*it).first = LLONG_MAX;

        it = min_element(diff.begin(), diff.end());
        if (temp == (*it).first) {
            ans += (*it).second;
        }

        if (ans == 0)
            cout << "0 ";
        else if (ans > 0)
            cout << "1 ";
        else
            cout << "-1 ";
        
    }


    return 0;
}