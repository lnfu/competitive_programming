// encryption by shifting

#include <bits/stdc++.h>

using namespace std;

int main() {
    string ciphertext;
    string secret;
    cin >> ciphertext;
    cin >> secret;

    int n = ciphertext.size();
    int m = secret.size();
    vector<char> ans(n, 0);

    for (int i = 0; i < m && i < n; i++)
        ans[i] = 'A' + (26 + ciphertext[i] - secret[i]) % 26;

    for (int i = 0; i < n - m; i++)
        ans[i+m] = 'A' + (26 + ciphertext[i+m] - ans[i]) % 26;

    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
    return 0;
}