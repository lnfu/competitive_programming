#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<char> stk;
    getchar(); // read '\n'
    for (int i = 0; i < n; i++) {
        char c = getchar();
        if (c == ' ')
            continue;
        
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                cout << c << ' ' << i;
                return 0;
            }

            char prev = stk.top();
            if (prev == '(' && c == ')') {
                stk.pop();
            } else if (prev == '[' && c == ']') {
                stk.pop();
            } else if (prev == '{' && c == '}') {
                stk.pop();
            } else {
                cout << c << ' ' << i;
                return 0;
            }
        }
        
    }
    cout << "ok so far";
    return 0;
}