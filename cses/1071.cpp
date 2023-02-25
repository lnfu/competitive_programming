#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long x, y;
        cin >> y >> x;
        if (x == y) {
            // n^2 - n + 1
            cout << x*x - x + 1;
        } else if (x < y) {
            long diff = y - x;
            if (y % 2 == 0) {
                cout << (y*y - y + 1) + diff;
            } else {
                cout << (y*y - y + 1) - diff;
            }
        } else {
            long diff = x - y;
            if (x % 2 == 0) {
                cout << (x*x - x + 1) - diff;
            } else {
                cout << (x*x - x + 1) + diff;
            }
        }
        cout << '\n';
    }
    return 0;
}