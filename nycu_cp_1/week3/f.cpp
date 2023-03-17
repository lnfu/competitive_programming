#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; // 10000
    int T; // 47
    cin >> N >> T;
    vector<tuple<int, int>> person_group;
    for (int i = 0; i < N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        person_group.push_back({temp1, temp2});
    }
    sort(person_group.begin(), person_group.end(), [](auto& a, auto& b) {
        return get<1>(a) > get<1>(b);
    });
    
    // for (const auto& person : person_group) {
    //     cout << get<0>(person) << ' ' << get<1>(person) << '\n';
    // }
    int ans = 0;
    // inside loop
    while (T--) {
        priority_queue<tuple<int, int>> pq;
        for (int i = 0; i < N; i++) {
            if (get<1>(person_group[i]) >= T)
                pq.push({get<0>(person_group[i]), i});
        }
        if (pq.empty())
            continue;
        ans += get<0>(pq.top());
        person_group.erase(person_group.begin() + get<1>(pq.top()));
    }
    // int time = T - 1;
    cout << ans;

    return 0;
}