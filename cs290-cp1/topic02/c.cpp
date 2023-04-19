#include <bits/stdc++.h>

using namespace std;

int main() {

    int N; cin >> N;

    vector<string> nameGroup;
    string s;
    getline(cin, s);
    while (getline(cin, s))
        nameGroup.push_back(s);
    
    int M = nameGroup.size();

    if (M == 1 || N <= 5) {
        cout << (N + 1) / 2 << ": " << nameGroup[0] << '\n';
        return 0;
    }

    if (M == 2 || N <= 6) {
        cout << (N + 1) / 2 << ": " << nameGroup[0] << '\n';
        cout << (N) << ": " << nameGroup[1] << '\n';
        return 0;
    }

    cout << (1) << ": " << nameGroup[1] << '\n';
    cout << (N + 1) / 2 << ": " << nameGroup[0] << '\n';
    cout << (N) << ": " << nameGroup[2] << '\n';
    if (M == 3 || N <= 11) {
        return 0;
    }





    return 0;
}