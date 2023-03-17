#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    getchar();
    while (T--) {
        string input;
        getline(cin, input);
        int maxNumber = input.size() + 1;

        string data = "$" + input;
        vector<int> next(maxNumber, 0);

        int prev = 0;
        int curr = 0;
        int last = 0;

        for (int i = 1; i < maxNumber; i++) {
            char temp = data[i];

            if (temp == '[') {
                curr = 0;
            } else if (temp == ']') {
                curr = last;
            } else if (temp == '<') {
                if (last > 0) {
                    next[prev] = next[curr];
                    curr = prev;
                    last--;
                }
            } else {
                // curr --> next[curr] to curr --> i --> next[curr];
                next[i] = next[curr];
                next[curr] = i;

                if (curr == last)
                    last = i;
                prev = curr;
                curr = i;
            }
        }


        for (int i = next[0]; i != 0; i = next[i]) {
            cout << data[i];
        }
    }
    return 0;
}