// colliding Encoding

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";

        set<string> pool;
        vector<char> mapping(26, -1);
        for (int j = 0; j < 26; j++) {
            cin >> mapping[j];
        }

        int N; cin >> N;
        bool col = false;
        while (N--) {
            string s; cin >> s;
            string s_new;
            for (const auto& c : s) {
                char num = mapping[c-'A'];
                s_new.push_back(num);
            }
            // cout << "TEST: " << s_new << endl;
            if (pool.find(s_new) != pool.end()) {
                // already
                col = true;
            }
            pool.insert(s_new);
        }

        if (col)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}