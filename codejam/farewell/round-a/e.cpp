#include <bits/stdc++.h>

using namespace std;

bool valid(const string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[(i+1) % s.size()])
            return false;
    }

    return true;
}

void backtrack(string& s, int pos, int time, int& minimum, int count) {
    // cout << "\nTEST: " << count << ' ' << s << ' ' << time << ' ';
    if (valid(s)) {
        minimum = min(minimum, time);
    }

    if (count > s.size() + 1) {
        return;
    }
    
    int i = pos;
    for (; ; i++, count++) {
        if (s[(26+i-1)%26] == s[(26+i)%26])
            break;
    }

    if (s[i] == 'P') {
        s[i] = 'R';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'S';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'P';
    }
    if (s[i] == 'R') {
        s[i] = 'P';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'S';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'R';
    }
    if (s[i] == 'S') {
        s[i] = 'P';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'R';
        backtrack(s, i, time+1, minimum, count);
        s[i] = 'S';
    }
}

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": ";

        string s; cin >> s;
        int minimum = INT_MAX;
        if (valid(s))
            cout << 0 << '\n';
        else {
            backtrack(s, 0, 0, minimum, 0);
            backtrack(s, 1, 0, minimum, 0);
            cout << minimum << '\n';
        }
    }
    return 0;
}

