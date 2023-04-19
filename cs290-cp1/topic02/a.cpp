// anagram counting
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;

    map<string, vector<string>> count;
    for (int i = 0; i < N; i++) {
        vector<int> alpha(26, 0);
        string input; cin >> input;
        for (const auto& c : input) {
            alpha[c - 'a']++;
        }
        string key;
        for (int j = 0; j < 26; j++) {
            key.push_back('a' + j);
            key.push_back('0' + alpha[j]);
        }
        // cout << key << '\n';
        count[key].push_back(input);
    }

    int maxNum = 0;
    string maxKey;
    for (const auto& [key, val] : count) {
        if (val.size() > maxNum) {
            maxNum = val.size();
            maxKey = key;
        }
    }

    cout << maxNum << endl;
    sort(count[maxKey].begin(), count[maxKey].end());
    for (const auto& v : count[maxKey]) {
        cout << v << '\n';
    }

    return 0;
}