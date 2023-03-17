#include <bits/stdc++.h>

using namespace std;

// a ^ p mod p
int cal(int root_p, int p, int a) {
    if (p == 0)
        return 1;
    if (p == 1)
        return a % root_p;
    int temp = cal(root_p, p / 2, a) % root_p;
    if (p % 2 == 0)
        return (temp * temp) % root_p;
    else
        return (temp * temp * a) % root_p;
}

int main() {
    int p, a;
    while (cin >> p >> a) {
        if (p == 0 && a == 0)
            break;
        // check prime
        bool isPrime = true;
        for (int i = 2; i * i < p; i++) {
            if (p % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << "no" << '\n';
            continue;
        }
        if (cal(p, p, a) == a)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}