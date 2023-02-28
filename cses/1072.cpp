#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++) {
        if (k == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (k == 2) {
            cout << 6 << '\n';
            continue;
        }
        cout << (k*k)*(k*k-1)/2 - 4*(k-2)*(k-1) << '\n';
    }

    return 0;
}