#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; // 1 ~ 26
    vector<bool> var_group;
    stack<bool> cal;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        var_group.push_back(temp == 'T' ? true : false);
    }
    int count = 0;
    char temp;
    while (cin >> temp) {
        if (isalpha(temp)) {
            cal.push(var_group[count++]);
        } else {
            if (temp == '-') {
                bool t = cal.top();
                cal.pop();
                cal.push(!t);
            }
            if (temp == '*') {
                bool t1 = cal.top();
                cal.pop();
                bool t2 = cal.top();
                cal.pop();
                cal.push(t1 && t2);
            }
            if (temp == '+') {
                bool t1 = cal.top();
                cal.pop();
                bool t2 = cal.top();
                cal.pop();
                cal.push(t1 || t2);
            }
        }
    }
    cout << (cal.top() ? 'T' : 'F') << endl;
    return 0;
}