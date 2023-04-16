// rainbow sort

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";

        int N; cin >> N;
        set<int> pool;
        vector<int> result;
        int prev = 0;
        bool canDo = true;
        for (int j = 0; j < N; j++) {
            int now; cin >> now;
            if (pool.find(now) != pool.end() && prev != now)
                canDo = false;
            if (now != prev)
                result.push_back(now);
            
            prev = now;
            pool.insert(now);
        }
        if (canDo) {
            for (const auto& num : result)
                cout << num << ' ';
            cout << '\n';
        }
        else 
            cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
} 