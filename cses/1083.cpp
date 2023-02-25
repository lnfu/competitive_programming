#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> exist(n, false);
    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp;
        exist[temp-1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!exist[i]) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}