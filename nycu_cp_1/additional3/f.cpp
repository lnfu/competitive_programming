#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        int cur = a;
        cout << "0.";
        while (c--) {
            cur *= 10;
            cout << cur / b;
            cur %= b;
        }
        cout << '\n';
    }
    return 0;
}