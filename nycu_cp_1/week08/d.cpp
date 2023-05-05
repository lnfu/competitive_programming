#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long temp = a / 2;
    for (int i = 1; i < b; i++) {
        temp %= a;
        temp *= temp;
    }
    cout << temp % a << endl;
    return 0;
}