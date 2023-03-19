#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << ((a % 3 == 0) ? "YES" : "NO") << '\n';
            continue;
        }

        if (a > b)
            swap(a, b);
        
        a -= 3 * (a / 3);
        b -= 3 * (a / 3);

        if (a == 1 && b == 2) {
            cout << "YES" << '\n';
            continue;
        }
        if (a == 2 && b == 4) {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}