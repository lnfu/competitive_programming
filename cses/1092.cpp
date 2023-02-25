#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 4 != 0 && (n + 1) % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    if (n % 2 == 1) {
        cout << n / 2 + 1 << endl;
        int fst = 1;
        while (fst < n) {
            cout << fst << ' ';
            fst += (fst % 2 == 0) ? 3 : 1;
        }
        cout << endl;
        cout << n / 2 << endl;
        int snd = 3;
        while (snd <= n) {
            cout << snd << ' ';
            snd += (snd % 2 == 0) ? 3 : 1;
        }
        cout << endl;
    } else {
        cout << n / 2 << endl;
        int fst = 2;
        while (fst < n) {
            cout << fst << ' ';
            fst += (fst % 2 == 1) ? 3 : 1;
        }
        cout << endl;
        cout << n / 2 << endl;
        int snd = 1;
        while (snd <= n) {
            cout << snd << ' ';
            snd += (snd % 2 == 1) ? 3 : 1;
        }
        cout << endl;
    }

    return 0;
}