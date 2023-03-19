#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        getchar();
        map<char, int> mp;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            char c = getchar();
            if (i == 0) {
                mp[c] = 1;
                continue;
            }

            if (i % 2 == 0) {
                // 1
                if (mp[c] == 0) {
                    mp[c] == 1;
                    continue;
                }
                if (mp[c] == 1)
                    continue;
                if (mp[c] == 2) {
                    ans = false;
                    break;
                }
            } else {
                // 2
                if (mp[c] == 0) {
                    mp[c] == 2;
                    continue;
                }
                if (mp[c] == 2)
                    continue;
                if (mp[c] == 1) {
                    ans = false;
                    break;
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}