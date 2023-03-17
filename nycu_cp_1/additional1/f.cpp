#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        if ((a + b) % 2 == 0)
            cout << "Stan wins" << '\n';
        else
            cout << "Ollie wins" << '\n';
    }
    return 0;
}