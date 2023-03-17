#include <iostream>

using namespace std;

const string cat = "MmEeOoWw";

bool valid(int status, char c) {
    return c == cat[status] || c == cat[status + 1];
}

bool jump(int status, char c) {
    status += 2;
    return valid(status, c);
}

void check(string& line) {
    int status = 0;
    bool begin = true;
    for (const auto& c : line) {
        if (begin) {
            if (!valid(status, c)) {
                cout << "NO" << '\n';
                return;
            }
            begin = false;
        }
        if (valid(status, c)) {
            continue;
        } else if (status == 6) {
            cout << "NO" << '\n';
            return;
        }
        if (jump(status, c)) {
            status += 2;
            continue;
        }

        cout << "NO" << '\n';
        return;
    }

    if (status != 6) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string line;
        cin >> line;
        check(line);
    }

    return 0;
}
