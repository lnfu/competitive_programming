#include <bits/stdc++.h>

using namespace std;

string s; // 1 ~ 100
vector<int> weight(101, 1);

long long ans = 0;

bool valid() {
    bool hasL = false;
    int vo = 0;
    int co = 0;
    for (const auto c : s) {
        if (c == 'L')
            hasL = true;

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vo++;
            co = 0;
        } else {
            co++;
            vo = 0;
        }

        if (vo >= 3 || co >= 3)
            return false;
    }

    return hasL;
}

void dfs(int index) {
    if (index >= s.size()) {
        // complete
        // cout << s << ' ';
        if (valid()) {
            // cout << "VALID";
            long long count = 1;
            for (int i = 0; i < s.size(); i++) {
                count *= weight[i];
            }
            ans += count;
        }
        // cout << endl;
        return;
    }


    if (s[index] != '_') {
        dfs(index + 1);
        return;
    }
    
    s[index] = 'L';
    weight[index] = 1;
    dfs(index + 1);

    s[index] = 'A';
    weight[index] = 5;
    dfs(index + 1);

    s[index] = 'B';
    weight[index] = 20;
    dfs(index + 1);

    // re
    s[index] = '_';
    weight[index] = 1;
}

int main() {
    cin >> s;

    dfs(0);
    
    cout << ans << endl;

    return 0;
}