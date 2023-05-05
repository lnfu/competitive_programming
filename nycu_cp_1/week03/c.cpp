#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& str) {
    vector<string> res;
    auto begin = str.begin();
    while (begin != str.end()) {
        auto end = find(begin, str.end(), ' ');
        res.push_back(string(begin, end));
        if (end == str.end())
            break;
        begin = end + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    while (cin >> t) {
        if (t == 0)
            break;
        map<string, vector<string>> mp;
        while (t--) {
            string line;
            getline(cin, line);
            if (line[line.size()-1] == '\n')
                line.pop_back();
            if (line[line.size()-1] == '\r')
                line.pop_back();
            if (line[line.size()-1] == '\n')
                line.pop_back();
            if (line[line.size()-1] == '\r')
                line.pop_back();
            if (line.size() == 0) {
                t++;
                continue;
            }
            vector<string> splitted_line = split(line);
            string name = splitted_line[0];
            for (int i = 1; i < splitted_line.size(); i++) {
                mp[splitted_line[i]].push_back(name);
            }
        }
        for (const auto& [key, value] : mp) {
            cout << key;
            sort(mp[key].begin(), mp[key].end());
            for (const auto& food : mp[key]) {
                cout << ' ' << food;
            }
            cout << '\n';
        }
        cout << endl;
    }

    return 0;
}